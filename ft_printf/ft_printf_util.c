/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:58:32 by dballini          #+#    #+#             */
/*   Updated: 2022/11/10 16:58:32 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
}

void	ft_putchar(char c, t_list *tab)
{
	tab->len += write(1, &c, 1);
}

void	ft_putnbr(int nb, t_list *tab)
{
	if (nb < 0)
	{
		ft_putchar('-', tab);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, tab);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48, tab);
}

void	ft_putunbr(unsigned int nb, t_list *tab)
{
	if (nb >= 10)
	{
		ft_putunbr(nb / 10, tab);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48, tab);
}

void	ft_puthex(unsigned long num, t_list *tab, const char c)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, tab, c);
		ft_puthex(num % 16, tab, c);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0', tab);
		else
		{
			if (c == 'x')
				ft_putchar(num - 10 + 'a', tab);
			if (c == 'X')
				ft_putchar(num - 10 + 'A', tab);
		}
	}
}
