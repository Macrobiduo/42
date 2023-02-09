/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:54:29 by dballini          #+#    #+#             */
/*   Updated: 2023/02/09 15:04:44 by dballini         ###   ########.fr       */
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
	struct s_list	*next;
}					t_list;

t_list		*ft_free_list(t_list *list);
void		ft_insert(char *argv, t_list **a);
long int	ft_atoi(const char *str);
int			ft_check_border(t_list *node, int pos, int nbr);
int			ft_check_compare(t_list *x, int a, int b, int c);
int			ft_find_minmax(t_list **a, char c);
int			ft_find_where(t_list *node, int nbr);
int			ft_get_number(t_list *head, int k);
int			ft_get_node_pos(t_list *node, int nbr);
int			check_arg(char **argv, int argc);
int			ft_checkdouble(t_list *astack, long int i);
int			ft_eval_move(int *mov_a, int *mov_b, int size);
int			ft_eval_nbr(t_list **a, t_list **b, int i);
void		ft_for_3(t_list **a);
void		ft_for_5(t_list **a, t_list **b);
void		ft_for_100(t_list **a, t_list **b);
t_list		*ft_remove_block(t_list **list, int nbr);
t_list		*ft_find_lis(t_list *a, int pos, int current, int best);
t_list		*ft_build_lis(t_list *a, t_list **lis);
t_list		*ft_find_next(t_list *a);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);
void		sa(t_list *a);
void		sb(t_list *b);
void		ss(t_list *a, t_list *b);
void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a, t_list **b);
void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b);
void		ft_conclude(t_list	**a);
void		ft_start(t_list **a, t_list **b, int argc);
void		ft_smart_push(int mov_a, int mov_b, t_list **a, t_list **b);
int			ft_exe_moves(int mov_b, t_list **b);
void		printflist(t_list *a);
#endif
