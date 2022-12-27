/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:54:33 by dballini          #+#    #+#             */
/*   Updated: 2022/12/16 18:54:33 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ss(t_list *a,t_list *b)
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
	t_list	*temp;

	temp = (*a)->next;
	ft_lstlast(*a)->next = *a;
	(*a)->next = NULL;
	*a = temp;
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	t_list	*temp;

	temp = (*b)->next;
	ft_lstlast(*b)->next = *b;
	(*b)->next = NULL;
	*b = temp;
	write(1, "rb\n", 3);
}

void	rr(t_list **a,t_list **b)
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
	prev->next = NULL;
}

void     rrb(t_list **b)
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
}

void      rrr(t_list **a, t_list **b)
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
}