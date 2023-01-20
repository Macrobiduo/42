/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:31:23 by dballini          #+#    #+#             */
/*   Updated: 2023/01/20 22:31:23 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char **argv, int argc)
{
	int		i;
	int		j;
	int		sign;

	j = 1;
	while (j < argc)
	{
		i = 0;
		sign = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == '+' || argv[j][i] == '-')
			{
				sign = 1;
				i++;
			}
			if (argv[j][i] == '+' || argv[j][i] == '-' && sign == 1)
				return (0);
			else
				if (!(argv[j][i] > 47 && argv[j][i]  < 58))
					return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_checkdouble(t_list *astack, long int i)
{
	if (i > 2147483647 || i < -2147483648)
		return (1);
	while (astack)
	{
		if (astack->number == i)
			return (1);
		astack = astack->next;
	}
	return (0);
}
