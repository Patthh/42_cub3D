#include "../../include/cub3D.h"

static int	map_valid(const char *line)
{
	const char	*valid;

	valid = " 01NSEW";
	if (!line || !*line)
		return (ft_error("\tEmpty map line"));
	while (*line)
	{
		if (!ft_strchr(valid, *line))
			return (ft_error("\tInvalid map character"));
		line++;
	}
	return (0);
}

// creates new grid with existing content + space for new line
static char	**map_grid(t_config *config, const char *line)
{
	char	**grid;
	int		i;

	grid = ft_calloc(config->map.height + 2, sizeof(char *));
	if (!grid)
		return (NULL);
	i = -1;
	while (++i < config->map.height)
		grid[i] = config->map.grid[i];
	grid[config->map.height] = ft_strdup(line);
	if (!grid[config->map.height])
	{
		while (i > 0)
			grid[--i] = NULL;
		ft_free_split(grid);
		return (NULL);
	}
	return (grid);
}

// appends a line to the map grid
static int	map_append(t_config *config, const char *line)
{
	char	**grid;

	grid = map_grid(config, line);
	if (!grid)
		return (ft_error("\tFailed to allocate map memory"));
	free(config->map.grid);
	config->map.grid = grid;
	config->map.height++;
	if ((size_t)config->map.width < ft_strlen(line))
		config->map.width = ft_strlen(line);
	return (0);
}

// tracks player start position
static int	map_player(t_config *config, const char *line)
{
	static int	count = 0;
	const char	*pointer;
	int			x_pos;

	x_pos = 0;
	pointer = line;
	while (*pointer)
	{
		if (*pointer == 'N' || *pointer == 'S' || *pointer == 'E'
			|| *pointer == 'W')
		{
			config->map.spawn = *pointer;
			config->map.player_x = x_pos;
			config->map.player_y = config->map.height;
			if (++count > 1)
				return (ft_error("\tMultiple player start positions"));
		}
		pointer++;
		x_pos++;
	}
	return (0);
}

// trims newline and trailing spaces
// validates trimmed line
// appends line to map grid
// checks player position
int	parse_map(t_config *config, char *line)
{
	char	*trimmed;

	if (!config || !line)
		return (ft_error("\tInvalid input parameters"));
	trimmed = ft_strtrim(line, "\n");
	if (!trimmed)
		return (ft_error("\tFailed to allocate memory for map line"));
	if (map_valid(trimmed) != 0)
	{
		free(trimmed);
		return (1);
	}
	if (map_append(config, trimmed) != 0)
	{
		free(trimmed);
		return (1);
	}
	if (map_player(config, trimmed) != 0)
	{
		free(trimmed);
		return (1);
	}
	free(trimmed);
	return (0);
}
