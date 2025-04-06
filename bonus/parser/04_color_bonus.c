/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_color_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:22:45 by aomont            #+#    #+#             */
/*   Updated: 2025/03/31 23:35:51 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

// validates a single RGB component (0-255, digits only)
static int	color_check(const char *str, int *value)
{
	int	i;
	int	num;

	if (!str || !*str)
		return (0);
	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	num = ft_atoi(str);
	if (num < 0 || num > 255)
		return (0);
	*value = num;
	return (1);
}

// validates color component format (count and empty checks)
static int	color_verify(char **components)
{
	int	i;

	i = 0;
	while (components[i])
		if (!*components[i++])
			return (ft_error_split(components, "\tEmpty color component"));
	if (i != 3)
		return (ft_error_split(components, "\tInvalid component count"));
	return (0);
}

// processes RGB components (trims and validates each)
static int	color_extract(char **comp, int *rgb)
{
	char	*trimmed;
	int		i;

	i = -1;
	while (++i < 3)
	{
		if (!comp[i])
			return (ft_error_split(comp, "\tInvalid color format"));
		trimmed = ft_strtrim(comp[i], " ");
		if (!trimmed)
			return (ft_error_split(comp, "\tMemory error"));
		free(comp[i]);
		comp[i] = trimmed;
		if (!color_check(comp[i], &rgb[i]))
			return (ft_error_split(comp, "\tInvalid color value"));
	}
	return (0);
}

// processes the string
static int	color_process(char *str, t_color *color)
{
	char	*trimmed;
	char	**comp;
	int		rgb[3];

	trimmed = ft_strtrim(str, " \n");
	if (!trimmed)
		return (ft_error("\tMemory error"));
	if (trimmed[0] == ',' || trimmed[ft_strlen(trimmed) - 1] == ',')
		return (free(trimmed), ft_error("\tInvalid comma placement"));
	comp = ft_split(trimmed, ',');
	free(trimmed);
	if (!comp)
		return (ft_error("\tMemory error"));
	if (color_verify(comp) || color_extract(comp, rgb))
		return (1);
	color->r = rgb[0];
	color->g = rgb[1];
	color->b = rgb[2];
	ft_free_split(comp);
	return (0);
}

int	parse_color(t_config *config, const char *line)
{
	t_color	*target;
	int		result;

	if (!config || !line)
		return (ft_error("\tInvalid parameters"));
	if (ft_strncmp(line, "F ", 2) == 0)
		target = &config->floor;
	else if (ft_strncmp(line, "C ", 2) == 0)
		target = &config->ceiling;
	else
		return (ft_error("\tInvalid color type"));
	if (target->r != -1 || target->g != -1 || target->b != -1)
		return (ft_error("\tColor already defined"));
	result = color_process((char *)line + 2, target);
	return (result);
}
