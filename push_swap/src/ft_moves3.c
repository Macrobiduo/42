/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:11:35 by dballini          #+#    #+#             */
/*   Updated: 2023/01/20 22:11:35 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!(*a))
		return ;
	temp = (*a);
	if ((*a)->next == NULL)
		(*a) = NULL;
	else
		(*a) = (*a)->next;
	if (b == NULL)
		ft_lstadd_front(b, ft_lstnew(temp->number));
	else
		ft_lstadd_front(b, temp);
	write(1, "pa\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!(*b))
		return ;
	temp = (*b);
	if ((*b)->next == NULL)
		(*b) = NULL;
	else
		(*b) = (*b)->next;
	if (a == NULL)
		ft_lstadd_front(a, ft_lstnew(temp->number));
	else
		ft_lstadd_front(a, temp);
	write(1, "pb\n", 3);
}
