#ifndef CUB3D_H
# define CUB3D_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

// MLX COLORS(RGBA)
# define GREY 0x555555FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define LIGHT_GREY  0xC0C0C0FF
# define DARK_GREY   0x404040FF
# define BLACK       0x000000FF
# define GREEN       0x00FF00FF
# define BLUE        0x0000FFFF
# define YELLOW      0xFFFF00FF
# define CYAN        0x00FFFFFF
# define MAGENTA     0xFF00FFFF
# define ORANGE      0xFFA500FF
# define PINK        0xFFC0CBFF
# define BROWN       0xA52A2AFF
# define PURPLE      0x800080FF
# define LIGHT_BLUE  0xADD8E6FF
# define DARK_GREEN  0x006400FF

// ANSI COLOR
# define RDE "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define PNK "\x1B[95m"
# define CRE "\x1B[0m"
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"
# define BHRED "\e[1;91m"

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

// DATA STRUCTURES
// Represents a color with RGB components
typedef struct s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

// Stores the map grid, dimensions, and player's starting position
typedef struct s_map
{
	char			**grid;
	int				width;
	int				height;
	double			player_x;
	double			player_y;
	char			spawn;
	int				is_valid;
}					t_map;

// Holds player position, direction and camera plane information
typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	char			direction;
	double			direction_x;
	double			direction_y;
	double			plane_x;
	double			plane_y;
}					t_player;

// Contains all configuration data parser from the .cub file
typedef struct s_config
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	t_color			floor;
	t_color			ceiling;
	t_player		player;
	t_map			map;
	int				flag;
}					t_config;

// Define the ray struct for ray calculations
typedef struct s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
}					t_ray;

// For wall rendering
typedef struct s_wall
{
	// Wall properties
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			perp_wall_dist;
	double			wall_x;
	int				tex_x;

	// Texture properties
	mlx_texture_t	*texture;
	double			step;
	double			tex_pos;

	// Wall hit information
	// 0 for x-side, 1 for y-side
	int				side;
	int				map_x;
	int				map_y;
}					t_wall;

//main structure
typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*screen;
	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*east_texture;
	mlx_texture_t	*west_texture;
	t_config		config;
	t_player		player;
	t_wall			wall;
	double			move_speed;
	double			rot_speed;
	uint32_t		floor_color;
	int				map_x;
	int				map_y;
}					t_game;

void				initializer(t_config *config);
int					init_game(t_game *game, int argc, char **argv);
void				init_player(t_game *game);

// PARSER
int					parser(t_config *config, int argc, char **argv);
int					parse_argument(int argc, char **argv);
int					parse_config(t_config *config, const char *filename);
int					parse_line(t_config *config, char *line);
int					parse_texture(t_config *config, const char *line);
int					parse_color(t_config *config, const char *line);
int					parse_map(t_config *config, char *line);
int					parse_validator(t_config *config);

// UTILS
int					ft_error(char *message);
int					ft_error_split(char **array, char *message);
void				ft_free_config(t_config *config);
void				ft_free_split(char **split);

// TONY LIBFT
int					ft_isspace(int c);

// CORE FUNCTION
void				print_core(void);
void				print_control(void);

//HOOKS
void				key_hook(mlx_key_data_t keydata, void *param);

// TEXTURE
int					load_textures(t_game *game);

// RENDER
void				render_frame(void *param);
void				render_walls(t_game *game);
void				draw_textured_wall(t_game *game, t_wall *wall, int x);
void				select_wall_texture(t_game *game, t_ray *ray, t_wall *wall);
void				calculate_wall_properties(t_game *game, \
t_ray *ray, t_wall *wall);
void				perform_dda(t_game *game, t_ray *ray, t_wall *wall);

#endif
