## VARIABLES
MAKEFLAGS += --no-print-directory

NAME			= cub3D
BONUS_NAME		= cub3D_bonus

LIBFT_NAME       = libft.a
MLX42_DIR        = MLX42/
MLX42_BUILD_DIR  = $(MLX42_DIR)build/

################################################################################
## DIRECTORIES
DIR_INC          = ./include/
DIR_SRC          = ./source/
DIR_BONUS_SRC    = ./bonus/
DIR_LIBFT        = ./libft/

INCLUDE          = -I include -I libft/include -I $(MLX42_DIR)include

################################################################################
## COMPILATION & FLAGS
CC               = cc
CFLAGS           = -Wall -Wextra -Werror -g -O0 #-fsanitize=address
HEADERS          = -I$(DIR_INC) -I include -I $(DIR_LIBFT)include -I $(MLX42_DIR)include
MLX              = -L$(MLX42_BUILD_DIR) -lmlx42 -ldl -lglfw -pthread -lm
LIBFT            = -L$(DIR_LIBFT) -lft
RM               = rm -rf

################################################################################
## SOURCES
SRCS             = $(DIR_SRC)core.c \
				$(DIR_SRC)init.c \
				$(DIR_SRC)key_hook.c \
				$(DIR_SRC)load_textures.c \
				$(DIR_SRC)main.c \
				$(DIR_SRC)render.c \
				$(DIR_SRC)walls.c \
				$(DIR_SRC)parser/00_parser.c \
				$(DIR_SRC)parser/01_argument.c \
				$(DIR_SRC)parser/02_line.c \
				$(DIR_SRC)parser/03_texture.c \
				$(DIR_SRC)parser/04_color.c \
				$(DIR_SRC)parser/05_map.c \
				$(DIR_SRC)parser/06_validator.c \
				$(DIR_SRC)utils/errors.c \
				$(DIR_SRC)utils/memory.c

BONUS_SRCS       = $(DIR_BONUS_SRC)core_bonus.c \
				$(DIR_BONUS_SRC)init_bonus.c \
				$(DIR_BONUS_SRC)key_hook_bonus.c \
				$(DIR_BONUS_SRC)load_textures_bonus.c \
				$(DIR_BONUS_SRC)main_bonus.c \
				$(DIR_BONUS_SRC)minimap_bonus.c \
				$(DIR_BONUS_SRC)render_bonus.c \
				$(DIR_BONUS_SRC)walls_bonus.c \
				$(DIR_BONUS_SRC)parser/00_parser_bonus.c \
				$(DIR_BONUS_SRC)parser/01_argument_bonus.c \
				$(DIR_BONUS_SRC)parser/02_line_bonus.c \
				$(DIR_BONUS_SRC)parser/03_texture_bonus.c \
				$(DIR_BONUS_SRC)parser/04_color_bonus.c \
				$(DIR_BONUS_SRC)parser/05_map_bonus.c \
				$(DIR_BONUS_SRC)parser/06_validator_bonus.c \
				$(DIR_BONUS_SRC)utils/errors_bonus.c \
				$(DIR_BONUS_SRC)utils/memory_bonus.c

OBJS             = $(SRCS:.c=.o)
BONUS_OBJS       = $(BONUS_SRCS:.c=.o)

TOTAL_FILES      = $(words $(SRCS))
COMPILED_FILES   = 0
BONUS_COMPILED_FILES = 0
DOTS             = $(shell printf ".%.0s" $(shell seq $(TOTAL_FILES)))
BONUS_TOTAL_FILES = $(words $(BONUS_SRCS))
BONUS_DOTS       = $(shell printf ".%.0s" $(shell seq $(BONUS_TOTAL_FILES)))

################################################################################
## RULES
all: $(DIR_LIBFT)$(LIBFT_NAME) $(MLX42_BUILD_DIR)libmlx42.a $(NAME)
	@printf "$(GREEN)Build complete! $(NAME) has been created.$(NC)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

bonus: $(DIR_LIBFT)$(LIBFT_NAME) $(MLX42_BUILD_DIR)libmlx42.a $(BONUS_NAME)
	@printf "\n$(GREEN)Bonus build complete! $(BONUS_NAME) has been created.$(NC)\n"

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX) -o $(BONUS_NAME)

$(DIR_LIBFT)$(LIBFT_NAME):
	@$(MAKE) -C $(DIR_LIBFT) || (printf "$(RED)Error building libft$(NC)\n" && exit 1)

$(MLX42_BUILD_DIR)libmlx42.a:
	@mkdir -p $(MLX42_BUILD_DIR)
	@cmake -S $(MLX42_DIR) -B $(MLX42_BUILD_DIR) || (printf "$(RED)Error configuring MLX42 with CMake$(NC)\n" && exit 1)
	@$(MAKE) -C $(MLX42_BUILD_DIR) || (printf "$(RED)Error building MLX42$(NC)\n" && exit 1)

%.o: %.c
	@$(eval COMPILED_FILES=$(shell printf $$(($(COMPILED_FILES) + 1))))
	@DOTS_LEFT=$(shell printf "$(DOTS)" | cut -c$(COMPILED_FILES)-) ; \
	printf "\33[2K\r$(CYAN)Currently compiling: $< $(COMPILED_FILES)/$(TOTAL_FILES)$(NC) 🟡%s"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@if [ $(COMPILED_FILES) -eq $(TOTAL_FILES) ]; then echo; fi

$(DIR_BONUS_SRC)%.o: $(DIR_BONUS_SRC)%.c
	@$(eval BONUS_COMPILED_FILES=$(shell printf $$(($(BONUS_COMPILED_FILES) + 1))))
	@BONUS_DOTS_LEFT=$(shell printf "$(BONUS_DOTS)" | cut -c$(BONUS_COMPILED_FILES)-) ; \
	printf "\33[2K\r$(CYAN)Currently compiling bonus: $< $(BONUS_COMPILED_FILES)/$(BONUS_TOTAL_FILES)$(NC) 🟡%s"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@if [ $(BONUS_COMPILED_FILES) -eq $(BONUS_TOTAL_FILES) ]; then echo; fi

clean:
	@printf "$(YELLOW)Cleaning object files...$(NC)\n"
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(DIR_LIBFT) clean
	@printf "\r$(GREEN)Object files cleaned!$(NC)\n"

fclean: clean
	@printf "$(YELLOW)Cleaning cub3D executable...$(NC)\n"
	@$(RM) $(NAME) $(BONUS_NAME) $(MLX42_DIR)build/
	@$(MAKE) -C $(DIR_LIBFT) fclean
	@printf "\r$(GREEN)Executable cleaned!$(NC)\n"

help:
	@printf "Using $(SHELL)\n"
	@printf "$(CYAN)📚 Available targets:$(NC)\n"
	@printf "$(GREEN)  make$(NC)        - Build the cub3D program\n"
	@printf "$(GREEN)  make bonus$(NC)  - Build the cub3D program w/ minimap and fps counter\n"
	@printf "$(GREEN)  make clean$(NC)  - Remove object files\n"
	@printf "$(GREEN)  make fclean$(NC) - Remove object files and executable\n"
	@printf "$(GREEN)  make re$(NC)     - Rebuild from scratch\n"
	@printf "$(GREEN)  make help$(NC)   - Display this help message\n"

re: fclean all

.PHONY: all clean fclean re help bonus

################################################################################
## COLORS
GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m
