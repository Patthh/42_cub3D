/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_texture_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:22:42 by aomont            #+#    #+#             */
/*   Updated: 2025/03/31 23:35:47 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

// skips leading spaces
// calculates length excluding trailing spaces
// extracts trimmed substring
static char	*check_whitespace(char *path)
{
	size_t	length;
	char	*trimmed;

	if (!path)
		return (NULL);
	while (ft_isspace((unsigned char)*path))
		path++;
	length = ft_strlen(path);
	while (length > 0 && ft_isspace((unsigned char)path[length - 1]))
		length--;
	trimmed = ft_substr(path, 0, length);
	return (trimmed);
}

// checks length and extension
// tests file accessibility with open function
static int	check_png(char *path)
{
	int	fd;

	if (!path || ft_strlen(path) < 5)
		return (ft_error("\tInvalid texture path: too short"));
	if (ft_strcmp(path + ft_strlen(path) - 4, ".png") != 0)
		return (ft_error("\tInvalid texture path: not .png"));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error("\tInvalid texture path: file not found"));
	close (fd);
	return (0);
}

// trims and validates a texture path
// checks for redefinitions and assigns it
static int	texture_path(char **texture, char *path)
{
	char	*trimmed;

	trimmed = check_whitespace(path);
	if (!trimmed)
		return (ft_error("\tEmpty texture path"));
	if (check_png(trimmed) != 0)
	{
		free (trimmed);
		return (1);
	}
	if (*texture)
	{
		free(trimmed);
		return (ft_error("\tTexture already defined"));
	}
	*texture = trimmed;
	return (0);
}

int	parse_texture(t_config *config, const char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (texture_path(&config->north, (char *)line + 3));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (texture_path(&config->south, (char *)line + 3));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (texture_path(&config->east, (char *)line + 3));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (texture_path(&config->west, (char *)line + 3));
	else
		return (ft_error("\tInvalid texture identifier"));
}
