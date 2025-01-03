/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:02:21 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/13 15:31:13 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f)
	{
		while (lst)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
	}
}
/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
void f_content(void *content)
{
    
    int *int_content = (int *)content;
    *int_content += 1;
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
	printf("avant +1: \n");
    t_list *temp = list;
    while (temp)
    {
        printf("content: %d ; ", *((int *)temp->content));
        temp = temp->next;
    }
	ft_lstiter(list, f_content);
	printf("\napres +1: \n");
    temp = list;
    while (temp)
    {
        printf("content: %d ; ", *((int *)temp->content));
        temp = temp->next;
    }
    return 0;
}  */