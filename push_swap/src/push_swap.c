/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:54:31 by dballini          #+#    #+#             */
/*   Updated: 2022/12/16 18:54:31 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char argv)
{
	if (argv > 47 )
}

int	main (int argc, char *argv[])
{
	struct s_list	a;
	struct s_list	b;
	int			i;

	i = 1;
	while (i < argc)
	{
		if(check_arg(*argv[i]))
			ft_lstadd_front(&a, argv[i]);
		else
			write(1, "Error\n", 7);
		i++;
	}
	return (0);
}