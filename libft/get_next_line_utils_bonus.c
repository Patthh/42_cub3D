/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:20:26 by pracksaw          #+#    #+#             */
/*   Updated: 2025/03/19 17:30:05 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_slen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_slen(str)]);
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *str1, char *str2)
{
	size_t		i;
	size_t		j;
	char		*ret;

	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	if (!str2)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_slen(str1) + ft_slen(str2) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
		ret[j++] = str1[i++];
	i = 0;
	while (str2[i])
		ret[j++] = str2[i++];
	ret[j] = '\0';
	free(str1);
	return (ret);
}
