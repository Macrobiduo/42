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
	int				*number;
	struct s_list		*next;
}					t_list;

void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);


#endif