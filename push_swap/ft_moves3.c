/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:11:35 by dballini          #+#    #+#             */
/*   Updated: 2023/01/20 22:11:35 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!(*a))
		return ;
	temp = (*a);
	if ((*a)->next == NULL)
		(*a) = NULL;
	else
		(*a) = (*a)->next;
	if (b == NULL)
		ft_lstadd_front(b, ft_lstnew(temp->number));
	else
		ft_lstadd_front(b, temp);
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!(*b))
		return ;
	temp = (*b);
	if ((*b)->next == NULL)
		(*b) = NULL;
	else
		(*b) = (*b)->next;
	if (a == NULL)
		ft_lstadd_front(a, ft_lstnew(temp->number));
	else
		ft_lstadd_front(a, temp);
	write(1, "pa\n", 3);
}

int	ft_check_border(t_list *node, int pos, int nbr)
{
	int				min;
	int				max;

	min = ft_find_minmax(&node, 'm');
	max = ft_find_minmax(&node, 'M');
	if (nbr < min)
		pos = ft_get_node_pos(node, min);
	else if (nbr > max)
		pos = ft_get_node_pos(node, max);
	return (pos);
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

t_list	*ft_free_list(t_list *list)
{
	t_list	*next;

	while (list->next)
	{
		next = list->next;
		free (list);
		list = next;
	}
	free (list);
	list = NULL;
	return (list);
}
