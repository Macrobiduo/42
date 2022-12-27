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

void	ft_start(t_list *a, t_list *b, int argc)
{
	if ((argc - 1) == 3)
	{

	}
	if ((argc - 1) == 5)
	{
		
	}
	if ((argc - 1) == 100)
	{
		
	}
	if ((argc - 1) == 500)
	{
		
	}
}

void	ft_printList(t_list *list)
{
	while (1)
	{
		printf("%d\n", list->number);
		if (list->next == NULL)
			break ;
		list = list->next;
	}
}

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

int	main (int argc, char *argv[])
{	
	t_list	*a;
	t_list	*b;
	int			i;

	a = NULL;
	b = NULL;
	if (argc < 2 || check_arg(argv, argc) == 0)
	{
		write(1,"Error\n", 6);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	//ft_start(a, b, argc);
	ft_printList(a);
	printf("-----------------\n");
	rra(&a);
	ft_printList(a);
	return (0);
}