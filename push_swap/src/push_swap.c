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

int	ft_get_node_pos(t_list *node, int nbr)
{
	unsigned int	pos;

	pos = 0;
	if (!node)
		return (0);
	while (node)
	{
		if (node->number == nbr)
			return (pos);
		pos++;
		node = node->next;
	}
	return (pos + 1);
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

int	ft_find_minmax(t_list **a, char c)
{
	int		nbr;
	t_list	*temp;

	temp = (*a);
	nbr = temp->number;
	if (c == 'M')
	{
		while (temp)
		{
			if (nbr < temp->number)
				nbr = temp->number;
			temp = temp->next;
		}
	}
	if (c == 'm')
	{
		while (temp)
		{
			if (nbr > temp->number)
				nbr = temp->number;
			temp = temp->next;
		}
	}
	return (nbr);
}

t_list	*ft_remove_block(t_list **list, int nbr)
{
	t_list	*prev;
	t_list	*head;

	head = (*list);
	prev = NULL;
	while (*list)
	{
		if (nbr == (*list)->number)
			break ;
		prev = (*list);
		(*list) = (*list)->next;
	}
	if (!prev)
	{
		head = (*list)->next;
		free (*list);
	}
	else
		prev->next = (*list)->next;
	(*list) = prev;
	return (head);
}

t_list	*ft_find_next(t_list *a)
{
	t_list	*temp;

	temp = a->next;
	while(temp)
	{
		if (a->number < temp->number)
			break ;
		temp = temp->next;
	}
	return (temp);
}

t_list	*ft_find_lis(t_list *a, int pos, int current, int best)
{
	t_list	*temp;
	t_list	*ret;

	while (a)
	{
		pos = 0;
		temp = a->next;
		current = a->number;
		while (temp)
		{
			if (temp->number > current)
			{
				pos++;
				current = temp->number;
			}
			temp = temp->next;
		}
		pos++;
		if (best < pos)
		{
			best = pos;
			ret = a;
		}
		a = a->next;
	}
	return (ret);
}

t_list	*ft_build_lis(t_list *a, t_list **lis)
{
	int		current;
	int		pos;
	int		best;
	t_list	*start;

	best = 0;
	while (start)
	{
		if (!(*lis))
			start = ft_find_lis(a, pos, current, best);
		else
			start = ft_find_next(start);
		if (start != NULL)
			ft_lstadd_back(lis, ft_lstnew(start->number));
	}
	return (*lis);
}

int	ft_bring_up_nbr(int i, int moves, t_list **a)
{
	if (moves > 0)
		while (moves > 0)
		{
			ra(a);
			i++;
			moves--;
		}
	else
		while (moves < 0)
		{
			rra(a);
			i++;
			moves++;
		}
	return (i);
}

int	ft_find_where(t_list *node, int nbr)
{
	unsigned int	pos;

	pos = 0;
	if (!node)
		return (0);
	while (node && node->number < nbr)
	{
		pos++;
		node = node->next;
	}
	return (pos);
}

int	ft_eval_move(t_list **a, int hold_number)
{
	int		next_distance;
	int		list_size;
	int		k;
	t_list	*temp;

	k = 0;
	if(!(*a))
		return (0);
	temp = (*a);
	list_size = ft_lstsize(*a);
	next_distance = ft_find_where(*a, hold_number);
	if (next_distance > list_size / 2)
		next_distance -= list_size;
	return (next_distance);
}

int	ft_eval_nbr(t_list **a, t_list **b)
{
	unsigned int	best;
	int				current;
	int				i;
	int				nbr;
	t_list			*temp;

	best = 500;
	i = 0;
	temp = (*b);
	while (temp)
	{
		current = ft_eval_move(a, temp->number);
		if (current < 0)
			current *= -1;
		if (current < best)
		{
			best = current;
			nbr = temp->number;
		}
		temp = temp->next;
	}
	return (nbr);
}

int	ft_smart_push(int i, int moves, t_list **a, t_list **b)
{
	
	return (i);
}

int	ft_for_100(t_list **a, t_list **b)
{
	int		len;
	int		moves;
	int		i;
	t_list	*lis;

	i = 0;
	lis = NULL;
	lis = ft_build_lis((*a), &lis);
	len = ft_lstsize((*a));
	while (len-- > 0)
	{	
		if ((*a)->number == lis->number)
		{
			ra(a);
			i++;
			if (lis->next != NULL)
				lis = lis->next;
		}
		else
		{
			pb(a, b);
			i++;
		}
	}
	while (*b)
	{
		moves = ft_eval_move(a, ft_eval_nbr(a, b));
		i = ft_smart_push(i, moves, b, a);
	}
	return (i);
}

void	ft_start(t_list **a, t_list **b, int argc)
{
	int	moves;
	if ((argc - 1) == 3)
		ft_for_3(a);
	else if ((argc - 1) == 5)
		ft_for_5(a, b);
	else if ((argc - 1) <= 100)
		moves = ft_for_100(a, b);
	else if ((argc - 1) <= 500)
	{
		
	}
	printf("MOSSE: %d", moves);
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

int	main (/*int argc, char *argv[]*/)
{	
	t_list	*a;
	t_list	*b;
	int			i;
	long int	tmp;

	int	argc = 11;
	char	*argv[] = {"a.out", "4", "8", "2", "9", "12", "1", "27", "13", "32", "10", NULL};
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
			ft_printlist(a);
			printf("-----------------\n");
			ft_start(&a, &b, argc);
			printf("-----------------\n");
			ft_printlist(a);
			printf("-----------------\n");
			ft_printlist(b);
	return (0);
}