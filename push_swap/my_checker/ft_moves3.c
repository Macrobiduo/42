/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:11:35 by dballini          #+#    #+#             */
/*   Updated: 2023/01/31 15:09:18 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

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

t_list	*ft_lstnew(int content)
{
	t_list	*p;

	p = (t_list *) malloc (sizeof(*p));
	if (!p)
		return (NULL);
	p->number = content;
	p->next = NULL;
	return (p);
}

