/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:55:47 by pracksaw          #+#    #+#             */
/*   Updated: 2023/09/24 12:06:00 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	const unsigned char	*src;
	unsigned char		uc;

	src = b;
	uc = (unsigned char)c;
	while (len > 0)
	{
		if (*src == uc)
			return ((void *)src);
		src++;
		len--;
	}
	return (NULL);
}
