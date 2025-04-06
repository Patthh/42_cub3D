/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:16:31 by pracksaw          #+#    #+#             */
/*   Updated: 2025/03/19 17:29:49 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# define FD_MAX 100000

size_t	ft_slen(char *str);
char	*gnl_strchr(char *str, int c);
char	*gnl_strjoin(char *str1, char *str2);
char	*ft_read_until_newline(int fd, char *str);
char	*ft_extract_line(char *str);
char	*ft_free_rem(char *line);
char	*get_next_line(int fd);
#endif
