#include "get_next_line_bonus.h"

char	*ft_read_until_newline(int fd, char *str)
{
	char	*buff;
	ssize_t	dim;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	dim = 1;
	while (!(gnl_strchr(str, '\n')) && dim > 0)
	{
		dim = read(fd, buff, BUFFER_SIZE);
		if (dim == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[dim] = '\0';
		str = gnl_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_extract_line(char *str)
{
	char	*new;
	int		i;

	i = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_free_rem(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_slen(line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

// static void	free_all_lines(char **string)
// {
// 	int	i;

// 	i = 0;
// 	while (i < FD_MAX)
// 	{
// 		if (string[i])
// 		{
// 			free(string[i]);
// 			string[i] = NULL;
// 		}
// 		i++;
// 	}
// }

char	*get_next_line(int fd)
{
	char		*ret;
	int			i;
	static char	*str[FD_MAX];

	i = 0;
	if (fd == -1)
	{
		while (i < FD_MAX)
		{
			if (str[i])
			{
				free(str[i]);
				str[i] = NULL;
			}
			i++;
		}
		return (NULL);
	}
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str[fd] = ft_read_until_newline(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	ret = ft_extract_line(str[fd]);
	return (str[fd] = ft_free_rem(str[fd]), ret);
}
