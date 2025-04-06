/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:44:59 by pracksaw          #+#    #+#             */
/*   Updated: 2023/10/02 18:14:29 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*begin;
	char	*last;
	char	*new;

	if (!s1 || !set)
		return (0);
	begin = (char *)s1;
	last = begin + ft_strlen(s1);
	while (*begin && isset(*begin, set))
		++begin;
	while (begin < last && isset(*(last - 1), set))
		--last;
	new = ft_substr(begin, 0, last - begin);
	return (new);
}

static int	isset(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}
