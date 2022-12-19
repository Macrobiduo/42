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

int	check_arg(char *argv)
{
	int		i;
	int		sign;
	i = 0;
	while (argv[i])
	{
		if (argv[i] == '+' || argv[i] == '-')
		{
			sign = 1;
			i++;
		}
		if (argv[i] == '+' || argv[i] == '-' && sign == 1)
			return (0);
		else
			if (!(argv[i] > 47 && argv[i] < 58))
				return (0);
		i++;
	}
	return (1);
}

int	main (int argc, char *argv[])
{	
	t_list	*a;
	t_list	*b;
	int			i;

	if (argc < 2)
	{
		write(1,"Error\n", 7);
		return (1);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if(check_arg(*argv[i]) == 1)
			{
				
			}
			else
				write(1, "Error\n", 7);
			i++;
		}
	}
	return (0);
}