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
