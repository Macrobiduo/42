/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:55:14 by dballini          #+#    #+#             */
/*   Updated: 2022/10/19 14:55:14 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list 
    *ft_lstnew(void *content)
{
    t_list *p;

    if(!(p = (t_list *)malloc(sizeof(*p))))
        return (NULL);
    p->content = content;
    p->next = NULL;
    return (p);
}