#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (!lst)
		return ;
	buf = *lst;
	while (buf)
	{
		*lst = (*lst)->next;
		del(buf->content);
		free(buf);
		buf = *lst;
	}
	lst = 0;
}
