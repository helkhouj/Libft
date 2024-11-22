/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <helkhouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:35:56 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/22 17:52:57 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *temp;

    if (!lst || !del)
        return;

    while (*lst)
    {
        temp = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = temp;
    }
    *lst = NULL;
}
void del_content(void *content)
{
    free(content);
}

int main (void)
{
    t_list *node1 = ft_lstnew(malloc(6));
    t_list *node2 = ft_lstnew(malloc(6));
    t_list *node3 = ft_lstnew(malloc(6));
    t_list *node4 = ft_lstnew(malloc(6));
    t_list *node5 = ft_lstnew(malloc(6));

    if (!node1 || !node2 || !node3 || !node4 || !node5)
    {
        free(node1);
        free(node2);
        free(node3);
        free(node4);
        free(node5);
        return(1);
    }

    

}
