/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:27:33 by dballini          #+#    #+#             */
/*   Updated: 2023/01/20 22:27:33 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_eval_move(int *mov_a, int *mov_b, int size)
{
	int		i;
	int		sum;
	int		best;
	int		best_i;

	best = 500;
	i = 0;
	while (i < size - 1)
	{
		if (mov_a[i] >=  0 && mov_b[i] >= 0)
			if (mov_a[i] >= mov_b[i])
				sum = mov_a[i];
			else
				sum = mov_b[i];
		if (mov_a[i] >= 0 && mov_b[i] < 0)
			sum = mov_a[i] + (mov_b[i] * -1);
		if (mov_a[i] < 0 && mov_b[i] >= 0)
			sum = (mov_a[i] * -1) + mov_b[i];
		if (mov_a[i] < 0 && mov_b[i] < 0)
			if (mov_a[i] <= mov_b[i])
				sum = mov_a[i] * -1;
			else
				sum = mov_b[i] * -1;
		if (sum < best)
		{
			best_i = i;
			best = sum;
		}
		i++;
	}
	return (best_i);
}

int	ft_eval_nbr(t_list **a, t_list **b)
{
	int		*mov_a;
	int		*mov_b;
	int		i;
	t_list	*temp;

	i = 0;
	temp = (*b);
	mov_a = malloc ((sizeof(int)) * ft_lstsize(*b) + 1);
	mov_b = malloc ((sizeof(int)) * ft_lstsize(*b) + 1);
	while (temp)
	{
		if (ft_find_where((*a), temp->number) <= ft_lstsize(*a) / 2)
			mov_a[i] = ft_find_where((*a), temp->number);
		else
			mov_a[i] = ft_find_where((*a), temp->number) - ft_lstsize(*a);
		if (i <= ft_lstsize(*b) / 2)
			mov_b[i] = i;
		else
			mov_b[i] = i - ft_lstsize(*b);
		i++;
		temp = temp->next;
	}
	i = ft_eval_move(mov_a, mov_b, ft_lstsize(*b));
	ft_smart_push(mov_a[i], mov_b[i], a, b);
	return (i);
}

void	ft_for_3(t_list **a)
{
	int		i;

	i = ft_check_compare(*a, 1, 2, 3);
	if (i == 1)
		sa(*a);
	else if (i == 2)
	{
		sa(*a);
		rra(a);
	}
	else if (i == 3)
		ra(a);
	else if (i == 4)
	{
		sa(*a);
		ra(a);
	}
	else if (i == 5)
		rra(a);
}

void	ft_for_5(t_list **a, t_list **b)
{
	t_list	*last;

	pb(a, b);
	pb(a, b);
	ft_for_3(a);
	while ((*b) != NULL)
	{
		last = ft_lstlast(*a);
		if ((*b)->number < (*a)->number)
			pa(a, b);
		else if ((*b)->number > last->number)
		{
			pa(a, b);
			ra(a);
		}
		else if ((*b)->number > (*a)->number && (*b)->number < last->number)
		{
			while ((*b)->number > (*a)->number)
				ra(a);
			pa(a, b);
			while ((*a)->number > ft_lstlast(*a)->number)
				rra(a);
		}
	}
}

void	ft_for_100(t_list **a, t_list **b)
{
	int		len;
	int		moves;
	t_list	*lis;

	lis = NULL;
	lis = ft_build_lis((*a), &lis);
	len = ft_lstsize((*a));
	while (len-- > 0)
	{	
		if ((*a)->number == lis->number)
		{
			ra(a);
			if (lis->next != NULL)
				lis = ft_remove_block(&lis, lis->number);
		}
		else
			pb(a, b);
	}
	while (*b)
		ft_eval_nbr(a, b);
}