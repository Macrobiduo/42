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

int	ft_get_number(t_list *head, int k)
{
	t_list	*temp;
	int			i;

	temp = head;
	i = 1;
	while (temp->next != NULL && i < k)
	{
		temp = temp->next;
		i++;
	}
	return (temp->number);
}

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
}

void	ft_printlist(t_list *list)    //
{
	if(!list)
	{
		write(1, "NULL\n", 5);
		return ;
	}
	while (1)
	{
		printf("%d\n", list->number);
		if (list->next == NULL)
			break ;
		list = list->next;
	}
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

}

void	ft_start(t_list **a, t_list **b, int argc)
{
	if ((argc - 1) == 3)
		ft_for_3(a);
	if ((argc - 1) == 5)
		ft_for_5(a, b);
	if ((argc - 1) == 100)
		ft_for_100(a, b);
	if ((argc - 1) == 500)
	{
		
	}
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
			if (argv[j][i] == '+' || argv[j][i] == '-' && sign == 1)
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

int	ft_checkdouble(t_list *astack, int i)
{
	while (astack)
	{
		if (astack->number == i)
			return (1);
		astack = astack->next;
	}
	return (0);
}

int	main (int argc, char *argv[])
{	
	t_list	*a;
	t_list	*b;
	int			i;
	int 			tmp;

	/* int	argc = 6;
	char	*argv[] = {"a.out", "55", "-11", "1", "4", "66", NULL}; */
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
			write(1,"Error, double num\n", 18);
			exit (1);
		}
		ft_lstadd_back(&a, ft_lstnew(tmp));
		i++;
	}
			ft_printlist(a);
			printf("-----------------\n");
			ft_start(&a, &b, argc);
			ft_printlist(a);
			printf("-----------------\n");
			ft_printlist(b);
	return (0);
}