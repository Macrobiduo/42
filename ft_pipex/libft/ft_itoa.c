/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:41:02 by dballini          #+#    #+#             */
/*   Updated: 2022/10/14 13:41:02 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_count(long int n)
{
	int		i;

	i = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_divide(char *p, long int num, int i)
{
	while (num >= 0 && i >= 0)
	{
		i--;
		p[i] = (num % 10) + '0';
		num /= 10;
		if (num == 0)
			break ;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	long int		num;
	int				i;
	char			*p;

	num = n;
	i = ft_count(num);
	if (n < 0)
	{
		p = (char *) malloc (i + 2);
		if (!p)
			return (NULL);
		p[0] = '-';
		num *= -1;
		i++;
	}
	else
	{
		p = (char *) malloc (i + 1);
		if (!p)
			return (NULL);
	}
	p[i] = '\0';
	p = ft_divide(p, num, i);
	return (p);
}
