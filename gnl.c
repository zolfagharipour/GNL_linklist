#include "gnl.h"


t_link	*ft_lstnew(int content)
{
	t_link	*ptr;

	ptr = (t_link *)malloc(sizeof(t_link));
	if (!(ptr))
		return (0);
	ptr->fd = content;
	ptr->next = 0;
	return (ptr);
}

void	ft_lstadd_back(t_link **lst, t_link *new)
{
	t_link	*tmp;

	tmp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_lstclear(t_link **lst)
{
	t_link	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			//del((*lst)->fd);
			free(*lst);
			*lst = tmp;
		}
	}
	*lst = NULL;
}

t_link	*gnl(int fd)
{
	static t_link	*buffer;
	t_link			*cur;
	cur = buffer;

	if (!buffer)
	{
		cur = ft_lstnew(fd);
		buffer = cur;
	}
	else
	{
		while (cur)
		{
			if (cur->fd == fd)
				return (cur);
			cur = cur->next;
		}
	}
	cur = ft_lstnew(fd);
	ft_lstadd_back(&buffer, cur);
	return (cur);
}



int main()
{
	t_link *cur;
	int i = 0;

	while (i < 10)
	{
		cur = gnl(i);
		printf("%ld\n", cur->fd);
		i++;
	}
		cur = gnl(0); 
		printf("%ld\n", cur->fd);
	cur = gnl(0);
	ft_lstclear(&cur);
}