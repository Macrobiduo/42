/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:33:54 by dballini          #+#    #+#             */
/*   Updated: 2023/01/30 18:28:23 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}					t_list;

void    ft_do_moves(char *line, t_list **a, t_list **b);
int	    ft_strcmp(char *s1, char *s2);
void	ft_insert(char *argv, t_list **a);
t_list	*ft_free_list(t_list *list);
int	    ft_checkdouble(t_list *astack, long int i);
int	    check_arg(char **argv, int argc);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
t_list	*ft_lstlast(t_list *lst);
long int	ft_atoi(const char *str);
t_list	*ft_lstnew(int content);


#endif