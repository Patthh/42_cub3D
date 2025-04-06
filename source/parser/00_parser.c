/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomont <aomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:22:25 by aomont            #+#    #+#             */
/*   Updated: 2025/03/31 22:22:26 by aomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	print_config_a(t_config *config)
{
	printf(BWHT "=== CONFIG CONTENT ===\n");
	printf("North Texture: %s\n", \
	config->north);
	printf("South Texture: %s\n", \
	config->south);
	printf("West Texture: %s\n", \
	config->west);
	printf("East Texture: %s\n", \
	config->east);
	printf("Floor Color: R=%d, G=%d, \
	 B=%d\n", config->floor.r, config->floor.g,
		config->floor.b);
	printf("Ceiling Color: R=%d, G=%d, \
	B=%d\n", config->ceiling.r,
		config->ceiling.g, config->ceiling.b);
	printf("Map Dimensions: Width=%d, \
	Height=%d\n", config->map.width,
		config->map.height);
	printf("Player Position: X=%.2f, \
	Y=%.2f, Direction=%c\n", \
		config->map.player_x, \
		config->map.player_y, config->map.spawn);
}

static void	print_config(t_config *config)
{
	int	i;

	i = 0;
	print_config_a(config);
	if (config->map.grid)
	{
		printf("Map Grid:\n\n");
		while (i < config->map.height)
			printf("%s\n", config->map.grid[i++]);
	}
	else
		printf("Map Grid: Not defined\n");
	printf("\n======================\n\n\n" CRE);
}

// reads file
// builds data structures
int	parse_config(t_config *config, const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error("\tFailed to open file"));
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (parse_line(config, line) != 0)
		{
			free(line);
			close(fd);
			get_next_line(-1);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
	return (0);
}

int	parser(t_config *config, int argc, char **argv)
{
	if (parse_argument(argc, argv) != 0)
		return (1);
	if (parse_config(config, argv[1]) != 0)
	{
		ft_free_config(config);
		return (1);
	}
	if (parse_validator(config) != 0)
	{
		ft_free_config(config);
		return (1);
	}
	print_config(config);
	return (0);
}

void	initializer(t_config *config)
{
	ft_memset(config, 0, sizeof(t_config));
	config->floor.r = -1;
	config->floor.g = -1;
	config->floor.b = -1;
	config->ceiling.r = -1;
	config->ceiling.g = -1;
	config->ceiling.b = -1;
}
