/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:58:11 by pracksaw          #+#    #+#             */
/*   Updated: 2025/03/31 23:36:17 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D_bonus.h"

int	load_textures(t_game *game)
{
	printf(CYN "North texture path: %s\n", game->config.north);
	printf("South texture path: %s\n", game->config.south);
	printf("East texture path: %s\n", game->config.east);
	printf("West texture path: %s\n" CRE, game->config.west);
	game->north_texture = mlx_load_png(game->config.north);
	if (!game->north_texture)
		return (ft_error("\tFailed to load north texture"));
	printf(BGRN "Loaded north texture successfully\n");
	game->south_texture = mlx_load_png(game->config.south);
	if (!game->south_texture)
		return (ft_error("\tFailed to load south texture"));
	printf("Loaded south texture successfully\n");
	game->east_texture = mlx_load_png(game->config.east);
	if (!game->east_texture)
		return (ft_error("\tFailed to load east texture"));
	printf("Loaded east texture successfully\n");
	game->west_texture = mlx_load_png(game->config.west);
	if (!game->west_texture)
		return (ft_error("\tFailed to load west texture"));
	printf("Loaded west texture successfully\n" CRE);
	print_control();
	return (0);
}
