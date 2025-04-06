/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <marvi@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:09:50 by pracksaw          #+#    #+#             */
/*   Updated: 2023/10/02 21:15:58 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t slen)
{
	unsigned char	*dst_tmp;

	if (!dst && !src)
		return (dst);
	dst_tmp = (unsigned char *)dst;
	while (slen--)
		*(char *)dst++ = *(char *)src++;
	return (dst_tmp);
}
