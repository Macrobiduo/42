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

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*p;

	p = (t_list *) malloc (sizeof(*p));
	if (!p)
		return (NULL);
	p->number = content;
	p->next = NULL;
	return (p);
}
