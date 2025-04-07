#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t	lil_len;

	lil_len = ft_strlen(lil);
	if (*lil == '\0')
		return ((char *)big);
	while (*big && len >= lil_len)
	{
		if (*big == *lil && ft_strncmp(big, lil, lil_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
