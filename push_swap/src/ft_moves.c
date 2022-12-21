/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:54:33 by dballini          #+#    #+#             */
/*   Updated: 2022/12/16 18:54:33 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void      sa(t_list *a)
{
	int		temp;

	temp = a->number;
	a->number = a->next->number;
	a->next->number = temp;
}

void      sb(t_list *b)
{
	int		temp;

	temp = b->number;
	b->number = b->next->number;
	b->next->number = temp;
}

t_list      ss(t_list *a,t_list *b)
{
	sa(a);
	sb(b);
}

void      rb(t_list *a,t_list *b)
{

}

void      rr(t_list *a,t_list *b)
{

}

void      ra(t_list *a,t_list *b)
{

}


t_list      rra(t_list *a,t_list *b)
{

}

t_list      rrb(t_list *a,t_list *b)
{

}

t_list      rrr(t_list *a,t_list *b)
{
      
}