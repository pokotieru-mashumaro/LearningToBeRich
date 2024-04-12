#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	del_content(void *content)
// {
// 	printf("Content: %s\n", (char *)content);
// }

// int	main(void)
// {
// 	t_list *lst = ft_lstnew("Hello");
// 	ft_lstadd_back(&lst, ft_lstnew("World"));
// 	ft_lstadd_back(&lst, ft_lstnew("aiu"));
// 	ft_lstadd_back(&lst, ft_lstnew("kakaka"));
// 	ft_lstadd_back(&lst, ft_lstnew("sasasa"));
// 	ft_lstiter(lst, del_content);
// }