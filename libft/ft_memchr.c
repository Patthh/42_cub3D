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
