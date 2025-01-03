/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:34:34 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/13 15:51:09 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/* #include <stdio.h>
#include <stdlib.h>
int main()
{
    t_list *list = NULL;
    t_list *new_node;
    int *str1 = malloc(sizeof(int));
    int *str2 = malloc(sizeof(int));
    int *str3 = malloc(sizeof(int));

    if (!str1 || !str2 || !str3)
    {
        printf("NULL");
        return 1;
    }
    *str1 = 1;
    *str2 = 2;
    *str3 = 3;
    new_node = ft_lstnew(str1);
    if (new_node)
        list = new_node;
    new_node = ft_lstnew(str2);
    if (new_node)
        list->next = new_node;
    new_node = ft_lstnew(str3);
    if (new_node)
        list->next->next = new_node;
    t_list *temp = list;
    while (temp)
    {
        printf("content: %d; ", *((int *)temp->content)); 
        temp = temp->next;
    }
    return 0;
} */
