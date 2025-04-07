#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*latest;

	latest = NULL;
	while (*s)
	{
		if (*s == (char)c)
			latest = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)latest);
}
