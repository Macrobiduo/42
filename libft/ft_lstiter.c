/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:43:46 by dballini          #+#    #+#             */
/*   Updated: 2022/10/19 15:43:46 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list *next;

    if (lst != NULL)
    {
        next = lst;
        while(1)
        {
            (*f)(next->content);
            next = next->next;
            if(next == NULL)
                return ;
        }
    }
}
