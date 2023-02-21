/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:33:54 by dballini          #+#    #+#             */
/*   Updated: 2023/02/21 17:18:07 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

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

void		ft_do_moves(char *line, t_list **a, t_list **b);
int			ft_strcmp(char *s1, char *s2);
void		ft_insert(char *argv, t_list **a);
t_list		*ft_free_list(t_list *list);
void		ft_free_checker(t_list **a, t_list **b);
int			ft_checkdouble(t_list *astack, long int i);
int			check_arg(char **argv, int argc);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
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
t_list		*ft_lstlast(t_list *lst);
long int	ft_atoi(const char *str);
t_list		*ft_lstnew(int content);
char		*get_next_line(int fd);
int			ft_strlen(const char *s);
char		*ft_strchr(char *s, int c);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_cut(char *src);
char		*ft_read(int fd, char *ret);
char		*ft_getextra(char *extra);
int			ft_find_minmax(t_list **a, char c);
int			leng(char const *s, char c);
char		**ft_split(char const *s, char c);
int			ft_counter(char const *s, char c);
void		*ft_calloc(size_t nelem, size_t elsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_strlen(const char *s);
int			ft_arrlen(char **arr);
void		ft_free_argv(char **argv);
#endif