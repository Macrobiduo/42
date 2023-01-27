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

int	ft_find_best(int mov_a, int mov_b, int sum)
{
	if (mov_a >= 0 && mov_b >= 0)
	{
		if (mov_a >= mov_b)
			sum = mov_a;
		else
			sum = mov_b;
	}
	if (mov_a >= 0 && mov_b < 0)
		sum = mov_a + (mov_b * -1);
	if (mov_a < 0 && mov_b >= 0)
		sum = (mov_a * -1) + mov_b;
	if (mov_a < 0 && mov_b < 0)
	{
		if (mov_a <= mov_b)
			sum = mov_a * -1;
		else
			sum = mov_b * -1;
	}
	return (sum);
}

int	ft_eval_move(int *mov_a, int *mov_b, int size)
{
	int		i;
	int		sum;
	int		best;
	int		best_i;

	best = 500;
	i = 0;
	while (i < size)
	{
		sum = ft_find_best(mov_a[i], mov_b[i], sum);
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

void	ft_for_100(t_list **a, t_list **b)
{
	int		len;
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
	free (lis);
	while (*b)
		ft_eval_nbr(a, b);
}
