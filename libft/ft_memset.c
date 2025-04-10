#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)b;
	while (i < len)
	{
		tmp[i] = c;
		i++;
	}
	return (b = tmp);
}
/*
#include <stdio.h>
#include <string.h>

int main () {
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);
   memset(str,'A',7);
   puts(str);

   memset(str+7,'B',7);
   puts(str);

   ft_memset(str,'E',4);
   puts(str);

   ft_memset(str+7,'Z',2);
   puts(str);

   return(0);
}
*/
