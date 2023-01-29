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

long int	ft_atoi(const char *str)
{
	long int	result;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
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

	pos = 0;
	if (!node || (nbr < node->number && nbr > ft_lstlast(node)->number))
		return (0);
	pos = ft_check_border(node, pos, nbr);
	if (pos == 0)
		while (!((node->number < nbr) && (node->next->number > nbr)))
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
	t_list		*temp;
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
