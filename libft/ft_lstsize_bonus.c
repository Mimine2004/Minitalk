/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:38:17 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/13 15:53:58 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int main()
{
    t_list *list = NULL;
    int *str1 = malloc(sizeof(int));
    int *str2 = malloc(sizeof(int));
    int *str3 = malloc(sizeof(int));
	int	i;

	i = 1;
	*str1 = 1;
	*str2 = 2;
	*str3 = 3;
    ft_lstadd_back(&list, ft_lstnew(str1));
    ft_lstadd_back(&list, ft_lstnew(str2));
    ft_lstadd_back(&list, ft_lstnew(str3));
    t_list *temp = list;
    while (temp)
    {
        printf("content: %d ; ", *((int *)temp->content));
        temp = temp->next;
    }
	i = ft_lstsize(list);
	printf("\nsize = 3 : %d\n",i);
    return 0;
} */