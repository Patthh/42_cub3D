/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:17:24 by pracksaw          #+#    #+#             */
/*   Updated: 2023/10/02 21:29:34 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*latest;

	latest = NULL;
	while (*s)
	{
		if (*s == (char)c)
			latest = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)latest);
}
