/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:07:57 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/13 15:44:46 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*temp;
	t_list	*list;
	t_list	*node;

	list = NULL;
	while (lst)
	{
		temp = f(lst->content);
		if (!temp)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		node = (ft_lstnew(temp));
		if (!node)
		{
			del(temp);
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
		lst = lst->next;
	}
	return (list);
}
/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del)
	{
		(*del)(lst->content);
		free(lst);
	}
}
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elst;

	if (del && lst && *lst)
	{
		while (lst && *lst)
		{
			elst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = elst;
		}
	}
}
void *f_content(void *content)
{
    
    int *int_content = (int *)content;
    *int_content += 1;
	return(int_content);
}
t_list	*ft_lstnew(void *content)
{
	t_list	*str;

	str = (t_list *)malloc(sizeof(t_list));
	if (!str)
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}
t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst && new)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
void free_content(void *content)
{
    free(content);
}
int main()
{
    t_list *list = NULL;
    char *str1 = strdup("1er");
    char *str2 = strdup("2eme");
    char *str3 = strdup("3eme");

    ft_lstadd_back(&list, ft_lstnew(str1));
    ft_lstadd_back(&list, ft_lstnew(str2));
    ft_lstadd_back(&list, ft_lstnew(str3));
    t_list *temp = list;
	printf("liste :\n");
    while (temp)
    {
        printf("content: %s ;", (char *)temp->content);
        temp = temp->next;
    }
    temp = ft_lstmap(list, f_content, free_content);
	printf("\nnew liste :\n");
	while (temp)
    {
        printf("content: %s ;", (char *)temp->content);
        temp = temp->next;
    }
    return 0;
} */