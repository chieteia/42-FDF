#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	if (!(ft_malloc((void **)&res, sizeof(t_list), 1)))
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}
