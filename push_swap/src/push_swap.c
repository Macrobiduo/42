/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:54:31 by dballini          #+#    #+#             */
/*   Updated: 2022/12/16 18:54:31 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_smart_push(int mov_a, int mov_b, t_list **a, t_list **b)
{
	while (mov_a > 0 && mov_b > 0)
	{
		rr(a, b);
		mov_a--;
		mov_b--;
	}
	while ((mov_a < 0 && mov_b < 0))
	{
		rrr(a, b);
		mov_a++;
		mov_b++;
	}
	while (mov_b != 0)
	{
		if (mov_b > 0)
		{
			rb(b);
			mov_b--;
		}
		else
		{
			rrb(b);
			mov_b++;
		}
	}
	while (mov_a > 0)
	{
		ra(a);
		mov_a--;
	}
	while (mov_a < 0)
	{
		rra(a);
		mov_a++;
	}
	pa(a, b);
}

void	ft_start(t_list **a, t_list **b, int argc)
{
	if ((argc - 1) == 3)
		ft_for_3(a);
	else if ((argc - 1) == 5)
		ft_for_5(a, b);
	else if ((argc - 1) > 5)
		ft_for_100(a, b);
}


void ft_conclude(t_list	**a)
{
	int		min;
	int		pos;

	min = ft_find_minmax(a, 'm');
	pos = ft_get_node_pos((*a), min);
	if (pos == 0)
		exit(0) ;
	if (pos >= ft_lstsize(*a) / 2)
		pos -= ft_lstsize(*a);
	while (pos != 0)
		if (pos > 0)
		{
			ra(a);
			pos--;
		}
		else
		{
			rra(a);
			pos++;
		}
}

int	main (int argc, char *argv[])
{	
	t_list	*a;
	t_list	*b;
	int			i;
	long int	tmp;

	a = NULL;
	b = NULL;
	if (argc < 2 || check_arg(argv, argc) == 0)
	{
		write(1,"Error\n", 6);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if (ft_checkdouble(a, tmp) == 1)
		{
			write(1,"Error\n", 6);
			exit (1);
		}
		ft_lstadd_back(&a, ft_lstnew(tmp));
		i++;
	}
	ft_start(&a, &b, argc);
	ft_conclude(&a);
	return (0);
}
