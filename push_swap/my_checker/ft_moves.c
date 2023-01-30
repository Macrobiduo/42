/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:54:33 by dballini          #+#    #+#             */
/*   Updated: 2023/01/30 18:27:20 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list *a)
{
	int		temp;

	temp = a->number;
	a->number = a->next->number;
	a->next->number = temp;
	write(1, "sa\n", 3);
}

void	sb(t_list *b)
{
	int		temp;

	temp = b->number;
	b->number = b->next->number;
	b->next->number = temp;
	write(1, "sb\n", 3);
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
	write(1, "ss\n", 3);
}

void	ra(t_list **a)
{
	t_list	*head;

	head = (*a);
	ft_lstlast(*a)->next = *a;
	(*a) = (*a)->next;
	head->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	t_list	*head;

	head = (*b);
	ft_lstlast(*b)->next = *b;
	(*b) = (*b)->next;
	head->next = NULL;
	write(1, "rb\n", 3);
}
