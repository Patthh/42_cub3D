/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomont <aomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:22:35 by aomont            #+#    #+#             */
/*   Updated: 2025/03/31 22:22:36 by aomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// 0 = invalid
// 1 = texture
// 2 = color
// 3 = map
static int	line_type(const char *line)
{
	const char	*p;

	if (!line)
		return (0);
	p = line;
	while (*p && ft_isspace(*p))
		p++;
	if (ft_strncmp(p, "NO ", 3) == 0 || ft_strncmp(p, "SO ", 3) == 0
		|| ft_strncmp(p, "WE ", 3) == 0 || ft_strncmp(p, "EA ", 3) == 0)
		return (1);
	if (ft_strncmp(p, "F ", 2) == 0 || ft_strncmp(p, "C ", 2) == 0)
		return (2);
	if (ft_strchr(" 01NSEW", *p) != NULL)
		return (3);
	return (0);
}

static int	line_handle(t_config *config, char *line, int type)
{
	if (type == 1)
		return (parse_texture(config, line));
	if (type == 2)
		return (parse_color(config, line));
	if (type == 3)
	{
		if (!config->flag)
			config->flag = 1;
		return (parse_map(config, line));
	}
	return (ft_error("\tInvalid line in map.cub"));
}

static char	*line_process(char *line, int type)
{
	char	*trimmed;

	if (!line)
		return (NULL);
	if (type == 3)
		trimmed = ft_strtrim(line, "\n");
	else
		trimmed = ft_strtrim(line, " \t\n");
	return (trimmed);
}

// returns 1 if line is empty or all whitespace; 0 otherwise
static int	line_empty(const char *line)
{
	if (!line)
		return (1);
	while (*line)
		if (!ft_isspace(*line++))
			return (0);
	return (1);
}

// uses appropriate parser or skips empty lines
int	parse_line(t_config *config, char *line)
{
	char	*processed;
	int		type;
	int		result;

	if (line_empty(line))
		return (0);
	type = line_type(line);
	processed = line_process(line, type);
	if (!processed)
		return (ft_error("\tFailed to process line"));
	if (config->flag && type != 3)
	{
		free(processed);
		return (ft_error("\tNon-map content after map started"));
	}
	result = line_handle(config, processed, type);
	free(processed);
	return (result);
}
