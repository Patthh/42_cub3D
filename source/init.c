/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:58:33 by pracksaw          #+#    #+#             */
/*   Updated: 2025/04/01 00:13:30 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// Check a row for valid positions and return 1 if found
static int	check_row(t_game *game, int dy, int radius)
{
	int	new_y;
	int	new_x;
	int	dx;

	dx = -radius;
	while (dx <= radius)
	{
		new_y = game->wall.map_y + dy;
		new_x = game->wall.map_x + dx;
		if (new_y >= 0 && new_y < game->config.map.height && new_x >= 0
			&& new_x < game->config.map.width)
		{
			if (game->config.map.grid[new_y][new_x] != '1')
			{
				game->player.pos_x = new_x + 0.5;
				game->player.pos_y = new_y + 0.5;
				return (1);
			}
		}
		dx++;
	}
	return (0);
}

static void	wall_stuck(t_game *game, int map_x, int map_y, int found)
{
	int	radius;
	int	dy;

	game->wall.map_x = map_x;
	game->wall.map_y = map_y;
	radius = 1;
	while (radius < 10 && !found)
	{
		dy = -radius;
		while (dy <= radius && !found)
		{
			if (check_row(game, dy, radius))
				found = 1;
			dy++;
		}
		radius++;
	}
}

void	validate_spawn(t_game *game)
{
	int	map_x;
	int	map_y;
	int	found;

	game->player.pos_x = game->config.map.player_x + 0.5;
	game->player.pos_y = game->config.map.player_y + 0.5;
	game->player.direction = game->config.map.spawn;
	map_x = (int)game->player.pos_x;
	map_y = (int)game->player.pos_y;
	if (game->config.map.grid[map_y][map_x] == '1')
	{
		printf(BRED "Warning: Initial spawn is inside a wall. \
Finding alternative...\n" CRE);
		found = 0;
		wall_stuck(game, map_x, map_y, found);
		printf(BWHT "\nPlayer spawn at\n\t X:%f Y:%f D:%c \n\n" CRE,
			game->player.pos_x, game->player.pos_y,
			game->player.direction);
	}
}

static void	set_player_w(t_game *game)
{
	game->player.direction_x = -1;
	game->player.direction_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = -0.66;
}

void	init_player(t_game *game)
{
	validate_spawn(game);
	if (game->player.direction == 'N')
	{
		game->player.direction_x = 0;
		game->player.direction_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (game->player.direction == 'S')
	{
		game->player.direction_x = 0;
		game->player.direction_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (game->player.direction == 'E')
	{
		game->player.direction_x = 1;
		game->player.direction_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (game->player.direction == 'W')
		set_player_w(game);
}
