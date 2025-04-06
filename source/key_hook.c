/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:58:36 by pracksaw          #+#    #+#             */
/*   Updated: 2025/03/31 22:58:37 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	move(t_game *game, double new_x, double new_y)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		new_x = game->player.pos_x + game->player.direction_x
			* game->move_speed;
		new_y = game->player.pos_y + game->player.direction_y
			* game->move_speed;
		if (game->config.map.grid[(int)game->player.pos_y] \
		[(int)new_x] != '1')
			game->player.pos_x = new_x;
		if (game->config.map.grid[(int)new_y] \
		[(int)game->player.pos_x] != '1')
			game->player.pos_y = new_y;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		new_x = game->player.pos_x - game->player.direction_x
			* game->move_speed;
		new_y = game->player.pos_y - game->player.direction_y
			* game->move_speed;
		if (game->config.map.grid[(int)game->player.pos_y] \
		[(int)new_x] != '1')
			game->player.pos_x = new_x;
		if (game->config.map.grid[(int)new_y][(int)game->player.pos_x] != '1')
			game->player.pos_y = new_y;
	}
}

static void	strafe(t_game *game, double new_x, double new_y)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		new_x = game->player.pos_x - \
		game->player.plane_x * game->move_speed;
		new_y = game->player.pos_y - \
		game->player.plane_y * game->move_speed;
		if (game->config.map.grid[(int)game->player.pos_y] \
		[(int)new_x] != '1')
			game->player.pos_x = new_x;
		if (game->config.map.grid[(int)new_y] \
		[(int)game->player.pos_x] != '1')
			game->player.pos_y = new_y;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		new_x = game->player.pos_x + game->player.plane_x
			* game->move_speed;
		new_y = game->player.pos_y + game->player.plane_y
			* game->move_speed;
		if (game->config.map.grid[(int)game->player.pos_y] \
		[(int)new_x] != '1')
			game->player.pos_x = new_x;
		if (game->config.map.grid[(int)new_y][(int)game->player.pos_x] != '1')
			game->player.pos_y = new_y;
	}
}

static void	rotate_left(t_game *game, double old_dir_x, double old_plane_x)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		old_dir_x = game->player.direction_x;
		game->player.direction_x = game->player.direction_x
			* cos(-game->rot_speed) - game->player.direction_y
			* sin(-game->rot_speed);
		game->player.direction_y = old_dir_x * sin(-game->rot_speed)
			+ game->player.direction_y * cos(-game->rot_speed);
		old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(-game->rot_speed)
			- game->player.plane_y * sin(-game->rot_speed);
		game->player.plane_y = old_plane_x * sin(-game->rot_speed)
			+ game->player.plane_y * cos(-game->rot_speed);
	}
}

static void	rotate_right(t_game *game, double old_dir_x, double old_plane_x)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		old_dir_x = game->player.direction_x;
		game->player.direction_x = game->player.direction_x
			* cos(game->rot_speed) - game->player.direction_y
			* sin(game->rot_speed);
		game->player.direction_y = old_dir_x * sin(game->rot_speed)
			+ game->player.direction_y * cos(game->rot_speed);
		old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(game->rot_speed)
			- game->player.plane_y * sin(game->rot_speed);
		game->player.plane_y = old_plane_x * sin(game->rot_speed)
			+ game->player.plane_y * cos(game->rot_speed);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	double	new_x;
	double	new_y;
	double	old_dir_x;
	double	old_plane_x;

	new_x = 0;
	new_y = 0;
	old_dir_x = 0;
	old_plane_x = 0;
	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	move(game, new_x, new_y);
	strafe(game, new_x, new_y);
	rotate_left(game, old_dir_x, old_plane_x);
	rotate_right(game, old_dir_x, old_plane_x);
}
