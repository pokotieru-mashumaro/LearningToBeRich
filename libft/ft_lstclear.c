#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst && *lst)
	{
		ft_lstclear(&(*lst)->next, del);
		del((*lst)->content);
		free(*lst);
		*lst = NULL;
	}
}

// void	del_content(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list *lst = ft_lstnew("Hello");
// 	ft_lstadd_back(&lst, ft_lstnew("World"));
// 	ft_lstadd_back(&lst, ft_lstnew("aiu"));
// 	ft_lstadd_back(&lst, ft_lstnew("kakaka"));
// 	ft_lstadd_back(&lst, ft_lstnew("sasasa"));
// 	ft_lstclear(&lst, del_content);
// 	printf("%s", (char *)lst->content);
// }