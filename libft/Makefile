	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@printf "$(GREEN)Build complete! $(NAME) has been created.$(NC)\n"

$(NAME): $(OBJECTS)
	@$(AR) -r $@ $?  > /dev/null 2>&1

bonus: $(OBJECTS) $(BOBJECTS)
	@$(AR) -r $(NAME) $?  > /dev/null 2>&1

%.o: %.c
	@$(CC) -c $(CFLAGS) $?

clean:
	@rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus

################################################################################
## COLORS
GREEN = \033[0;32m
NC = \033[0m
