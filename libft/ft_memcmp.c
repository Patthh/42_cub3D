#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	const unsigned char	*tp1;
	const unsigned char	*tp2;

	tp1 = b1;
	tp2 = b2;
	while (len > 0)
	{
		if (*tp1 != *tp2)
			return ((int)(*tp1 - *tp2));
		tp1++;
		tp2++;
		len--;
	}
	return (0);
}
