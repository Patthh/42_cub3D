#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *)s);
}
