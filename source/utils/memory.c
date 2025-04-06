/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomont <aomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:23:00 by aomont            #+#    #+#             */
/*   Updated: 2025/03/31 22:23:01 by aomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	ft_free_pointer(char **pointer)
{
	if (*pointer)
	{
		free (*pointer);
		*pointer = NULL;
	}
}

void	ft_free_config(t_config *config)
{
	int	i;

	ft_free_pointer(&config->north);
	ft_free_pointer(&config->south);
	ft_free_pointer(&config->east);
	ft_free_pointer(&config->west);
	if (config->map.grid)
	{
		i = 0;
		while (i < config->map.height)
		{
			ft_free_pointer(&config->map.grid[i]);
			i++;
		}
		free(config->map.grid);
		config->map.grid = NULL;
	}
}

// frees a split string array
void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}
