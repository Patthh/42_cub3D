/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomont <aomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:22:32 by aomont            #+#    #+#             */
/*   Updated: 2025/03/31 22:22:33 by aomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	check_directory(char *path)
{
	int	fd;

	if (!path)
		return (0);
	fd = open(path, O_DIRECTORY | O_RDONLY);
	if (fd == -1)
		return (0);
	close (fd);
	return (1);
}

static int	check_file(char *path)
{
	int	fd;

	if (!path)
		return (1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	close (fd);
	return (0);
}

static int	check_cub(char *filename)
{
	size_t	length;

	if (!filename)
		return (1);
	length = ft_strlen(filename);
	if (length < 5)
		return (1);
	if (ft_strcmp(filename + length - 4, ".cub") != 0)
		return (1);
	return (0);
}

// argument validation
int	parse_argument(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error("\tUsage: ./cub3D path/to/map.cub"));
	if (!argv || !argv[1])
		return (ft_error("\tInvalid argument array"));
	if (check_directory(argv[1]))
		return (ft_error("\tCannot use directory"));
	if (check_file(argv[1]))
		return (ft_error("\tCannot access file (check permissions/path)"));
	if (check_cub(argv[1]))
		return (ft_error("\tInvalid file extension (must be .cub)"));
	return (0);
}
