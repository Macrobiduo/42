/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:33:57 by dballini          #+#    #+#             */
/*   Updated: 2023/01/31 17:52:20 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	check_arg(char **argv, int argc)
{
	int		i;
	int		j;
	int		sign;

	j = 0;
	while (++j < argc)
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
				if (!(argv[j][i] > 47 && argv[j][i] < 58))
					return (0);
			i++;
		}
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

void	ft_free_list(t_list *list)
{
	t_list	*next;

	if (list != NULL)
	{
		while (list->next)
		{
			next = list->next;
			free (list);
			list = next;
		}
	}
	free (list);
	list = NULL;
}

void	ft_insert(char *argv, t_list **a)
{
	long int	tmp;

	tmp = ft_atoi(argv);
	if (ft_checkdouble(*a, tmp) == 1)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	ft_lstadd_back(a, ft_lstnew(tmp));
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void    ft_do_moves(char *line, t_list **a, t_list **b)
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

void	ft_get_line(t_list **a, t_list **b)
{
	char        *line;

	line = get_next_line(0);
	ft_do_moves(line, a, b);
	while (line != NULL)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		ft_do_moves(line, a, b);
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

void	ft_okornot(t_list **a, t_list **b)
{
	int		prev;
	int		min;
	int		max;

	min = ft_find_minmax(a, 'm');
	max = ft_find_minmax(a, 'M');
	if ((*b) != NULL || (*a)->number != min || ft_lstlast(*a)->number != max)
	{
		write(1, "KO\n", 3);
		ft_free_list(*b);
		exit (1);
	}
	prev = (*a)->number;
	while ((*a)->next != NULL)
	{
		*a = (*a)->next;
		if ((*a)->number < prev)
		{
			write(1, "KO\n", 3);
			exit (1);
		}
	}
	write (1, "OK\n", 3);
}

int	main(int argc, char *argv[])
{	
	t_list		*a;
	t_list		*b;
	int			i;

	a = NULL;
	b = NULL;
	if (argc < 2 || check_arg(argv, argc) == 0)
	{
		write(1, "Error\n", 6);
		ft_free_list(a);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		ft_insert(argv[i], &a);
		i++;
	}
	ft_get_line(&a, &b);
	ft_okornot(&a, &b);
	ft_free_list(a);
	return (0);
}
