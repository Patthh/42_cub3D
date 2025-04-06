/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:58:25 by pracksaw          #+#    #+#             */
/*   Updated: 2025/03/31 23:36:30 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D_bonus.h"

// Perform DDA(Digital Differential Analyzer) to find wall hit
// wall -> Map position
// if (ray) Jump to next map square
// if (wall) Check if ray has hit a wall
void	perform_dda(t_game *game, t_ray *ray, t_wall *wall)
{
	int	hit;

	hit = 0;
	wall->map_x = (int)game->player.pos_x;
	wall->map_y = (int)game->player.pos_y;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			wall->map_x += ray->step_x;
			wall->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			wall->map_y += ray->step_y;
			wall->side = 1;
		}
		if (wall->map_y >= 0 && wall->map_y < game->config.map.height
			&& wall->map_x >= 0 && wall->map_x < game->config.map.width
			&& game->config.map.grid[wall->map_y][wall->map_x] == '1')
			hit = 1;
	}
}

// Calculate wall properties (height, distance, etc)
// if (wall->side == 0) Calculate distance projected on camera direction
// wall->line_height Calculate height of line to draw on screen
// wall->draw_start Calculate lowest and highest pixel to fill in current stripe
// if (wall->side == 0) Calculate where exactly the wall was hit
void	calculate_wall_properties(t_game *game, t_ray *ray, t_wall *wall)
{
	if (wall->side == 0)
		wall->perp_wall_dist = (wall->map_x - game->player.pos_x + (1
					- ray->step_x) / 2) / ray->dir_x;
	else
		wall->perp_wall_dist = (wall->map_y - game->player.pos_y + (1
					- ray->step_y) / 2) / ray->dir_y;
	wall->line_height = (int)(WINDOW_HEIGHT / wall->perp_wall_dist);
	wall->draw_start = -wall->line_height / 2 + WINDOW_HEIGHT / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + WINDOW_HEIGHT / 2;
	if (wall->draw_end >= WINDOW_HEIGHT)
		wall->draw_end = WINDOW_HEIGHT - 1;
	if (wall->side == 0)
		wall->wall_x = game->player.pos_y + wall->perp_wall_dist
			* ray->dir_y;
	else
		wall->wall_x = game->player.pos_x + wall->perp_wall_dist
			* ray->dir_x;
	wall->wall_x -= floor(wall->wall_x);
}

// Select appropriate texture based on wall direction
// if (wall->side == 0) Choose wall texture based on which side 
//was hit and ray direction
// wall->tex_x X coordinate on the texture
// wall->step Calculate step for texture mapping
void	select_wall_texture(t_game *game, t_ray *ray, t_wall *wall)
{
	if (wall->side == 0)
	{
		if (ray->dir_x > 0)
			wall->texture = game->east_texture;
		else
			wall->texture = game->west_texture;
	}
	else
	{
		if (ray->dir_y > 0)
			wall->texture = game->south_texture;
		else
			wall->texture = game->north_texture;
	}
	wall->tex_x = (int)(wall->wall_x * wall->texture->width);
	if ((wall->side == 0 && ray->dir_x > 0) || (wall->side == 1
			&& ray->dir_y < 0))
		wall->tex_x = wall->texture->width - wall->tex_x - 1;
	wall->step = 1.0 * wall->texture->height / wall->line_height;
	wall->tex_pos = (wall->draw_start - WINDOW_HEIGHT / 2 + wall->line_height
			/ 2) * wall->step;
}

// Draw the vertical line with texture
void	draw_textured_wall(t_game *game, t_wall *wall, int x)
{
	int			y;
	int			tex_y;
	uint8_t		*pixel;
	uint32_t	color;

	y = wall->draw_start;
	while (y < wall->draw_end)
	{
		tex_y = (int)wall->tex_pos & (wall->texture->height - 1);
		wall->tex_pos += wall->step;
		pixel = &wall->texture->pixels[(tex_y * wall->texture->width
				+ wall->tex_x) * 4];
		color = (pixel[0] << 24) | (pixel[1] << 16) \
		| (pixel[2] << 8) | pixel[3];
		mlx_put_pixel(game->screen, x, y, color);
		y++;
	}
}
