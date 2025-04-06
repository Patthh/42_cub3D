/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:20:56 by pracksaw          #+#    #+#             */
/*   Updated: 2023/10/02 19:33:18 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 1)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*retu;
	const char	*digits = "0123456789";

	len = nbr_len(n);
	retu = malloc(sizeof(char) * (len + 1));
	if (!retu)
		return (NULL);
	retu[len] = 0;
	if (n == 0)
		retu[0] = '0';
	if (n < 0)
		retu[0] = '-';
	while (n)
	{
		if (n > 0)
			retu[--len] = digits[n % 10];
		else
			retu[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	return (retu);
}
