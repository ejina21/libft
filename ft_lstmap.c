#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*begin;

	if (!lst)
		return (0);
	begin = ft_lstnew(f(lst->content));
	if (!begin)
		return (0);
	lst = lst->next;
	list = begin;
	while (lst)
	{
		list->next = ft_lstnew(f(lst->content));
		if (!list->next)
			ft_lstclear(&begin, del);
		lst = lst->next;
		list = list->next;
	}
	return (begin);
}
