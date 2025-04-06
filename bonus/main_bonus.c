/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:58:14 by pracksaw          #+#    #+#             */
/*   Updated: 2025/03/31 23:36:20 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D_bonus.h"

int	init_game(t_game *game, int argc, char **argv)
{
	game->mlx = NULL;
	game->screen = NULL;
	game->minimap = NULL;
	game->north_texture = NULL;
	game->south_texture = NULL;
	game->east_texture = NULL;
	game->west_texture = NULL;
	initializer(&game->config);
	if (parser(&game->config, argc, argv) != 0)
		return (1);
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!game->mlx)
		return (ft_error("\tFailed to initialize MLX"));
	game->screen = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->minimap = mlx_new_image(game->mlx, MINIMAP_RADIUS * 2, MINIMAP_RADIUS
			* 2);
	if (!game->screen || !game->minimap)
		return (ft_error("\tFailed to create images"));
	if (load_textures(game) != 0)
		return (1);
	init_player(game);
	game->move_speed = 0.05;
	game->rot_speed = 0.03;
	return (0);
}

void	cleanup_game(t_game *game)
{
	if (game->screen)
		mlx_delete_image(game->mlx, game->screen);
	if (game->minimap)
		mlx_delete_image(game->mlx, game->minimap);
	if (game->north_texture)
		mlx_delete_texture(game->north_texture);
	if (game->south_texture)
		mlx_delete_texture(game->south_texture);
	if (game->east_texture)
		mlx_delete_texture(game->east_texture);
	if (game->west_texture)
		mlx_delete_texture(game->west_texture);
	if (game->mlx)
		mlx_terminate(game->mlx);
	ft_free_config(&game->config);
}

// Main B
int	main(int argc, char **argv)
{
	t_game	game;

	if (init_game(&game, argc, argv) != 0)
		return (1);
	mlx_key_hook(game.mlx, &key_hook, &game);
	mlx_loop_hook(game.mlx, &render_frame, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	print_core();
	return (0);
}
