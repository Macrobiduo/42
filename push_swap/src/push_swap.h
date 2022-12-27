/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:54:29 by dballini          #+#    #+#             */
/*   Updated: 2022/12/16 18:54:29 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				number;
	struct s_list		*next;
}					t_list;

void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_atoi(const char *str);
void      sa(t_list *a);
void      sb(t_list *b);
void      ss(t_list *a,t_list *b);
void      ra(t_list **a);
void      rb(t_list **b);
void      rr(t_list **a,t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void      rrr(t_list **a, t_list **b);
int		ft_lstsize(t_list *lst);


#endif