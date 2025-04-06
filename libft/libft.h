/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:16:31 by pracksaw          #+#    #+#             */
/*   Updated: 2025/03/19 17:15:43 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line_bonus.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// c-type.h

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

// string.h

void				ft_bzero(void *s, size_t n);
void				*ft_memchr(void const *str, int c, size_t n);
void				*ft_memcpy(void *dest, void const *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *str, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
size_t				ft_strlcpy(char *dest, char const *src, size_t n);
size_t				ft_strlen(char const *str);
char				*ft_strnstr(char const *haystack, char const *needle,
						size_t n);
char				*ft_strrchr(char const *str, int c);
char				*ft_strchr(char const *str, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strstr(const char *big, const char *little);

// stdlib.h

int					ft_atoi(char const *str);
void				*ft_calloc(size_t count, size_t n);

// Additional

char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strdup(char const *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strstr(const char *big, const char *little);

// bonus(link listed)

t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
		void (*del)(void *));
int					ft_lstsize(t_list *lst);

#endif
