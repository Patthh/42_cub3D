/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:58:20 by pracksaw          #+#    #+#             */
/*   Updated: 2025/03/31 23:36:26 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D_bonus.h"

void	render_ceiling_floor(t_game *game)
{
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	int			x;
	int			y;

	ceiling_color = (game->config.ceiling.r << 24) \
	| (game->config.ceiling.g << 16) \
	| (game->config.ceiling.b << 8) | 0xFF;
	floor_color = (game->config.floor.r << 24) | (game->config.floor.g << 16) \
	| (game->config.floor.b << 8) | 0xFF;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (y < WINDOW_HEIGHT / 2)
				mlx_put_pixel(game->screen, x, y, ceiling_color);
			else
				mlx_put_pixel(game->screen, x, y, floor_color);
			x++;
		}
		y++;
	}
}

// ray->camera_x Calculate ray position and direction
// ray->delta_dist Length of ray from current position to next x or y-side
static void	init_ray_a(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray->dir_x = game->player.direction_x + game->player.plane_x
		* ray->camera_x;
	ray->dir_y = game->player.direction_y + game->player.plane_y
		* ray->camera_x;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
}

// Initialize ray for current x-coordinate
// if (ray->dir_x < 0) Calculate step and initial side_dist
static void	init_ray(t_game *game, t_ray *ray, int x)
{
	init_ray_a(game, ray, x);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x
				- (int)game->player.pos_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((int)game->player.pos_x + 1.0
				- game->player.pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y
				- (int)game->player.pos_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((int)game->player.pos_y + 1.0
				- game->player.pos_y) * ray->delta_dist_y;
	}
}

// Main wall rendering function
void	render_walls(t_game *game)
{
	t_ray	ray;
	t_wall	wall;
	int		x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		init_ray(game, &ray, x);
		perform_dda(game, &ray, &wall);
		calculate_wall_properties(game, &ray, &wall);
		select_wall_texture(game, &ray, &wall);
		draw_textured_wall(game, &wall, x);
		x++;
	}
}

// ft_memset for clearing the screen
void	render_frame(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_memset(game->screen->pixels, 0, game->screen->width
		* game->screen->height * sizeof(uint32_t));
	render_ceiling_floor(game);
	render_walls(game);
	render_minimap(game);
	if (mlx_image_to_window(game->mlx, game->screen, 0, 0) < 0)
	{
		printf(RDE "Error: Failed to put image to window: %s\n" CRE,
			mlx_strerror(mlx_errno));
		ft_error("\tFailed to put image to window");
	}
	if (mlx_image_to_window(game->mlx, game->minimap, 5, 5) < 0)
	{
		printf("Error: Failed to put minimap to window: %s\n",
			mlx_strerror(mlx_errno));
		ft_error("\tFailed to put minimap to window");
	}
}
