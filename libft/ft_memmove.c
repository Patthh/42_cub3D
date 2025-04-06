/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:09:50 by pracksaw          #+#    #+#             */
/*   Updated: 2023/09/24 05:31:44 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp;

	src_tmp = src;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		dst_tmp = dst;
		while (len--)
			*dst_tmp++ = *src_tmp++;
	}
	else
	{
		dst_tmp = (unsigned char *)dst + len;
		src_tmp = src + len;
		while (len--)
			*--dst_tmp = *--src_tmp;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int main() {
    char source[] = "Hello, world!";
    char destination[23];

    //size_t numBytes = sizeof(source);

    size_t numBytes = 9;

    // Using ft_memmove
    ft_memmove(destination, source, numBytes);

    // Using standard memmove for comparison
    char std_destination[20];
    memmove(std_destination, source, numBytes);

    printf("Source: %s\n", source);
    printf("ft_memmove Destination: %s\n", destination);
    printf("memmove Destination: %s\n", std_destination);

    if (memcmp(destination, std_destination, numBytes) == 0) {
        printf("Both memory moves are equal.\n");
    } else {
        printf("Memory moves are different.\n");
    }

    return 0;
}
*/
