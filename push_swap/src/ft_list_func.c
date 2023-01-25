/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:20:24 by dballini          #+#    #+#             */
/*   Updated: 2023/01/20 22:20:24 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	pos = 0;
	current = 0;
	start = a;
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
