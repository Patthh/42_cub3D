/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomont <aomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:22:50 by aomont            #+#    #+#             */
/*   Updated: 2025/03/31 22:22:51 by aomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// validates textures, colors and player
static int	validate_config(t_config *config)
{
	if (!config->north || !config->south || !config->east || !config->west)
		return (ft_error("\tMissing texture definition"));
	if (config->floor.r == -1 || config->floor.g == -1 || config->floor.b == -1)
		return (ft_error("\tMissing floor color"));
	if (config->ceiling.r == -1 || config->ceiling.g == -1
		|| config->ceiling.b == -1)
		return (ft_error("\tMissing ceiling color"));
	if (config->map.spawn == '\0')
		return (ft_error("\tNo player start position"));
	if (config->map.player_x < 0 || config->map.player_y < 0)
		return (ft_error("\tInvalid player position"));
	return (0);
}

static char	**validate_init(t_config *config)
{
	char	**visited;
	int		y;

	visited = ft_calloc(config->map.height + 1, sizeof(char *));
	if (!visited)
		return (NULL);
	y = 0;
	while (y < config->map.height)
	{
		visited[y] = ft_calloc(config->map.width + 1, sizeof(char));
		if (!visited[y])
		{
			ft_free_split(visited);
			return (NULL);
		}
		y++;
	}
	visited[y] = NULL;
	return (visited);
}

// checks out of bounds cells
// stops if visited, wall or space
// floods valid cells
static int	flood_fill(t_config *config, int y, int x, char **array)
{
	char	c;

	if (y < 0 || y >= config->map.height || x < 0 || x >= config->map.width)
		return (ft_error("\tMap not enclosed"));
	c = config->map.grid[y][x];
	if (array[y][x] || c == '1' || c == ' ')
		return (0);
	if (c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (0);
	array[y][x] = 1;
	if (flood_fill(config, y - 1, x, array)
		|| flood_fill(config, y + 1, x, array)
		|| flood_fill(config, y, x - 1, array)
		|| flood_fill(config, y, x + 1, array))
		return (1);
	return (0);
}

static int	validate_map(t_config *config)
{
	char	**visited;

	visited = validate_init(config);
	if (!visited)
		return (ft_error("\tFailed to allocate validator memory"));
	if (flood_fill(config, config->map.player_y, config->map.player_x, visited))
	{
		ft_free_split(visited);
		return (1);
	}
	ft_free_split(visited);
	return (0);
}

int	parse_validator(t_config *config)
{
	if (validate_config(config) != 0)
		return (1);
	if (validate_map(config) != 0)
		return (1);
	return (0);
}
