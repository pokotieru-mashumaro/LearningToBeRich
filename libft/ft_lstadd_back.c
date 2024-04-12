#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*stock;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	stock = *lst;
	while (stock->next)
		stock = stock->next;
	stock->next = new;
}
