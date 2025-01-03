/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:39:16 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/13 10:12:29 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
    while (temp)
    {
        printf("content: %s\n", (char *)temp->content);
        temp = temp->next;
    }
    ft_lstclear(&list, free_content);
    if (list == NULL)
        printf("La liste est vide.\n");
    return 0;
}*/
