#include "libft.h"

static size_t	ft_count(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			++ret;
			while (*s && *s != c)
				++s;
		}
		else
		{
			++s;
		}
	}
	return (ret);
}

static void	ft_free_split(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}

static int	process_substring(const char **s, char c, char **retu, size_t *i)
{
	size_t	len;

	len = 0;
	while (**s && **s != c && ++len)
		++(*s);
	retu[*i] = ft_substr(*s - len, 0, len);
	if (!retu[*i])
	{
		ft_free_split(retu);
		return (0);
	}
	++(*i);
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**retu;
	size_t	i;

	retu = malloc(sizeof(char *) * ((ft_count(s, c)) + 1));
	if (!s || !(retu))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!process_substring(&s, c, retu, &i))
				return (NULL);
		}
		else
		{
			++s;
		}
	}
	retu[i] = NULL;
	return (retu);
}
