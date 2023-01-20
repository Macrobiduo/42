/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:08:37 by dballini          #+#    #+#             */
/*   Updated: 2023/01/20 22:08:37 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = (*a)->next;
	ft_lstlast(*a)->next = *a;
	(*a)->next = NULL;
	*a = temp;
	temp = (*b)->next;
	ft_lstlast(*b)->next = *b;
	(*b)->next = NULL;
	*b = temp;
	write(1, "rr\n", 3);
}

void	rra(t_list **a)
{
	t_list	*current;
	t_list	*prev;

	current = (*a);
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	current->next = (*a);
	(*a) = current;
	if (prev)
		prev->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	t_list	*current;
	t_list	*prev;

	current = (*b);
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	current->next = (*b);
	(*b) = current;
	prev->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	t_list	*current;
	t_list	*prev;

	current = (*b);
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	current->next = (*b);
	(*b) = current;
	prev->next = NULL;
	current = (*a);
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	current->next = (*a);
	(*a) = current;
	prev->next = NULL;
	write(1, "rrr\n", 4);
}
