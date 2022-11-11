/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:20:53 by dballini          #+#    #+#             */
/*   Updated: 2022/11/10 17:20:53 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_c(va_list args, t_p *tab)
{
	int	c;

	c = va_arg(args, int);
	tab->len += write(1, &c, 1);
}

void	ft_is_s(va_list args, t_p *tab)
{
	char	*s;

	s = va_arg(args, char *);
	tab->len += ft_strlen(s);
	ft_putstr(s);
}

void	ft_is_d(va_list args, t_p *tab)
{
	int	d;

	d = va_arg(args, int);
	ft_putnbr(d, tab);
}

void	ft_is_p(va_list args, t_p *tab)
{
	unsigned long	p;

	p = va_arg(args, unsigned long);
	if (!p)
		tab->len += write(1, "(nil)", 5);
	else
	{
		tab->len += write(1, "0x", 2);
		ft_puthex(p, tab, 'x');
	}	
}

void	ft_is_x(va_list args, t_p *tab, const char *format)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	ft_puthex(x, tab, *format);
}
