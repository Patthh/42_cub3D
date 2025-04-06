/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:46:28 by pracksaw          #+#    #+#             */
/*   Updated: 2023/09/29 18:00:16 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = number * size;
	ptr = malloc(total_size);
	if (number == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	if (ptr != NULL)
		ft_memset(ptr, 0, total_size);
	return (ptr);
}
