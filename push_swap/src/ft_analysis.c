/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:24:27 by dballini          #+#    #+#             */
/*   Updated: 2023/01/20 22:24:27 by dballini         ###   ########.fr       */
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

int	ft_find_where(t_list *node, int nbr)
{
	unsigned int	pos;
	int				min;
	int				max;

	min = ft_find_minmax(&node, 'm');
	max = ft_find_minmax(&node, 'M');
	pos = 0;
	if (!node || (nbr < node->number && nbr > ft_lstlast(node)->number))
		return (0);
	if (nbr < min)
		pos = ft_get_node_pos(node, min);
	else if (nbr > max)
		pos = ft_get_node_pos(node, max) + 1;
	else
		while (!(node->number < nbr && node->next->number > nbr))
		{
			pos++;
			node = node->next;
			if (node->next == NULL)
			{
				pos++;
				break ;
			}
		}
	if (node && node->number < nbr)
		pos++;
	return (pos);
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
