#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * (len +1));
	if (!new)
		return (0);
	ft_strlcpy(new, s1, len + 1);
	ft_strlcat(new, s2, len + 1);
	return (new);
}
