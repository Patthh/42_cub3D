/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:14:45 by pracksaw          #+#    #+#             */
/*   Updated: 2023/08/27 17:30:02 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10] = "Hello,";

    printf("Original buffer: %s\n", buffer);

    // Using memset to set the buffer to a known state
    memset(buffer, 'X', sizeof(buffer));
    printf("Buffer after memset: %s\n", buffer);

    // Using ft_bzero to zero out the buffer
    ft_bzero(buffer, sizeof(buffer));
    printf("Buffer after ft_bzero: %s\n", buffer);

    return 0;
}
*/
