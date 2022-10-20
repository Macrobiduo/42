/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:00:13 by dballini          #+#    #+#             */
/*   Updated: 2022/10/19 15:00:13 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *tmp;

    if (lst)
    {
        if(*lst == NULL)
            *lst = new;
        else
        {
            tmp = ft_lstlast(*(lst));
            tmp->next = new;
        }
    }
}