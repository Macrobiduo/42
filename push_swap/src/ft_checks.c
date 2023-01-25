/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:31:23 by dballini          #+#    #+#             */
/*   Updated: 2023/01/20 22:31:23 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_compare(t_list *x, int a, int b, int c)
{
	if (ft_get_number(x, a) > ft_get_number(x, b))
		if (ft_get_number(x, b) < ft_get_number(x, c))
			if (ft_get_number(x, a) < ft_get_number(x, c))
				return (1);
	if (ft_get_number(x, a) > ft_get_number(x, b))
		if (ft_get_number(x, b) > ft_get_number(x, c))
			if (ft_get_number(x, a) > ft_get_number(x, c))
				return (2);
	if (ft_get_number(x, a) > ft_get_number(x, b))
		if (ft_get_number(x, b) < ft_get_number(x, c))
			if (ft_get_number(x, a) > ft_get_number(x, c))
				return (3);
	if (ft_get_number(x, a) < ft_get_number(x, b))
		if (ft_get_number(x, b) > ft_get_number(x, c))
			if (ft_get_number(x, a) < ft_get_number(x, c))
				return (4);
	if (ft_get_number(x, a) < ft_get_number(x, b))
		if (ft_get_number(x, b) > ft_get_number(x, c))
			if (ft_get_number(x, a) > ft_get_number(x, c))
				return (5);
	return (0);
}

int	check_arg(char **argv, int argc)
{
	int		i;
	int		j;
	int		sign;

	j = 1;
	while (j < argc)
	{
		i = 0;
		sign = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == '+' || argv[j][i] == '-')
			{
				sign = 1;
				i++;
			}
			if ((argv[j][i] == '+' || argv[j][i] == '-') && sign == 1)
				return (0);
			else
				if (!(argv[j][i] > 47 && argv[j][i]  < 58))
					return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_checkdouble(t_list *astack, long int i)
{
	if (i > 2147483647 || i < -2147483648)
		return (1);
	while (astack)
	{
		if (astack->number == i)
			return (1);
		astack = astack->next;
	}
	return (0);
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
