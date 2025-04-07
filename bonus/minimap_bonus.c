#include "../include/cub3D_bonus.h"

static void	draw_fps(t_game *game, mlx_image_t *img)
{
	char	*fps;
	char	*fps_n;

	fps_n = ft_itoa(1 / game->mlx->delta_time);
	fps = ft_strjoin("FPS: ", fps_n);
	mlx_delete_image(game->mlx, img);
	img = mlx_put_string(game->mlx, fps, WINDOW_WIDTH - 100, 0);
	free(fps);
	free(fps_n);
}

static void	draw_player_icon(t_game *game, \
int player_screen_x, int player_screen_y)
{
	int	x;
	int	y;

	y = -PLAYER_SIZE / 2;
	while (y < PLAYER_SIZE / 2)
	{
		x = -PLAYER_SIZE / 2;
		while (x < PLAYER_SIZE / 2)
		{
			mlx_put_pixel(game->minimap, player_screen_x + x, player_screen_y
				+ y, RED);
			x++;
		}
		y++;
	}
}

// Check player position and direction
// printf("Player position: x=%f, y=%f\n", game->player.pos_x,
//	game->player.pos_y);
// printf("Player direction: x=%f, y=%f\n", game->player.direction_x,
//	game->player.direction_y);
// Check map_x and map_y bounds
// printf("map_x=%d, map_y=%d\n", map_x, map_y);
static void	draw_player(t_game *game, mlx_image_t *img, int player_screen_x,
		int player_screen_y)
{
	int	dir_x;
	int	dir_y;
	int	x;

	draw_player_icon(game, player_screen_x, player_screen_y);
	x = 0;
	while (x < PLAYER_SIZE * 2)
	{
		dir_x = player_screen_x + (int)(game->player.direction_x * x);
		dir_y = player_screen_y + (int)(game->player.direction_y * x);
		if (dir_x >= 0 && dir_x < MINIMAP_RADIUS * 2 && dir_y >= 0
			&& dir_y < MINIMAP_RADIUS * 2)
			mlx_put_pixel(game->minimap, dir_x, dir_y, DARK_GREEN);
		x++;
	}
	draw_fps(game, img);
}

static void	render_mini_grid(t_game *game, int player_screen_x,
		int player_screen_y, double y)
{
	int	x;

	x = 0;
	while (x < MINIMAP_RADIUS * 2)
	{
		game->map_x = (int)(game->player.pos_x + (x - player_screen_x)
				/ MINIMAP_SCALE);
		game->map_y = (int)(game->player.pos_y + (y - player_screen_y)
				/ MINIMAP_SCALE);
		if (game->map_y >= 0 && game->map_y < game->config.map.height
			&& game->map_x >= 0 && game->map_x < game->config.map.width)
		{
			if (game->config.map.grid[game->map_y][game->map_x] == '1')
				mlx_put_pixel(game->minimap, x, y, GREY);
			else if (game->config.map.grid[game->map_y][game->map_x] == '0'
				|| game->config.map.grid[game->map_y][game->map_x] \
				== game->player.direction)
				mlx_put_pixel(game->minimap, x, y, WHITE);
		}
		x++;
	}
}

void	render_minimap(t_game *game)
{
	static mlx_image_t	*img;
	int					player_screen_x;
	int					player_screen_y;
	double				x;
	double				y;

	x = 0;
	y = 0;
	game->floor_color = (game->config.floor.r << 24) \
	| (game->config.floor.g << 16) | (game->config.floor.b << 8) | 0xFF;
	player_screen_x = MINIMAP_RADIUS;
	player_screen_y = MINIMAP_RADIUS;
	while (y < MINIMAP_RADIUS * 2)
	{
		while (x < MINIMAP_RADIUS * 2)
			mlx_put_pixel(game->minimap, x++, y, game->floor_color);
		y++;
	}
	y = 0;
	while (y < MINIMAP_RADIUS * 2)
	{
		render_mini_grid(game, player_screen_x, player_screen_y, y);
		y++;
	}
	draw_player(game, img, player_screen_x, player_screen_y);
}
