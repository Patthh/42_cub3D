#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	(void)f;
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
