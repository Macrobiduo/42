/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:33:57 by dballini          #+#    #+#             */
/*   Updated: 2023/02/22 14:45:51 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_do_moves(char *line, t_list **a, t_list **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(*a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(*b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b);
}

void	ft_free_checker(t_list **a, t_list **b)
{
	write (1, "KO\n", 3);
	ft_free_list(*a);
	if (*b)
		ft_free_list(*b);
	exit (1);
}

void	ft_okornot(t_list **a, t_list **b)
{
	int		prev;
	int		min;
	int		max;
	t_list	*temp;

	min = ft_find_minmax(a, 'm');
	max = ft_find_minmax(a, 'M');
	if ((*b) != NULL || (*a)->number != min || ft_lstlast(*a)->number != max)
		ft_free_checker(a, b);
	prev = (*a)->number;
	temp = *a;
	while ((*a)->next != NULL)
	{
		*a = (*a)->next;
		if ((*a)->number < prev)
			ft_free_checker(a, b);
	}
	ft_free_list(temp);
	write (1, "OK\n", 3);
}

void	ft_get_line(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	ft_do_moves(line, a, b);
	free (line);
	while (line != NULL)
	{
		line = get_next_line(0);
		if (line == NULL)
		{
			free (line);
			break ;
		}
		ft_do_moves(line, a, b);
		free (line);
	}
	ft_okornot(a, b);
}

int	main(int argc, char *argv[])
{	
	t_list		*a;
	t_list		*b;
	int			i;
	int			k;

	k = 0;
	a = NULL;
	b = NULL;
	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_arrlen(argv);
		i = -1;
		k = 1;
	}
	ft_errors(argc, argv, k);
	while (++i < argc)
		ft_insert(argv[i], &a);
	if (k == 1)
		ft_free_argv(argv);
	ft_get_line(&a, &b);
	return (0);
}
