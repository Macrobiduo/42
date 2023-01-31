/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:54:33 by dballini          #+#    #+#             */
/*   Updated: 2023/01/31 17:54:09 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list *a)
{
	int		temp;

	temp = a->number;
	a->number = a->next->number;
	a->next->number = temp;
}

void	sb(t_list *b)
{
	int		temp;

	temp = b->number;
	b->number = b->next->number;
	b->next->number = temp;
}

void	ss(t_list *a, t_list *b)
{
	int		temp;

	temp = a->number;
	a->number = a->next->number;
	a->next->number = temp;
	temp = b->number;
	b->number = b->next->number;
	b->next->number = temp;
}

void	ra(t_list **a)
{
	t_list	*head;

	head = (*a);
	ft_lstlast(*a)->next = *a;
	(*a) = (*a)->next;
	head->next = NULL;
}

void	rb(t_list **b)
{
	t_list	*head;

	head = (*b);
	ft_lstlast(*b)->next = *b;
	(*b) = (*b)->next;
	head->next = NULL;
}
