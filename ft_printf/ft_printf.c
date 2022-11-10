/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:59:10 by dballini          #+#    #+#             */
/*   Updated: 2022/11/08 13:59:10 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_u(va_list args, t_list *tab)
{
	unsigned int	u;
	unsigned int	max;

	max = 4294967295;
	u = va_arg(args, unsigned int);
	if ((int)u < 0)
	{
		u += max + 1;
	}
	ft_putunbr(u, tab);
}

void	ft_what_arg(va_list args, const char *format, t_list *tab)
{
	if (*format == 'c')
		ft_is_c(args, tab);
	if (*format == 's')
		ft_is_s(args, tab);
	if (*format == 'd' || *format == 'i')
		ft_is_d(args, tab);
	if (*format == 'p')
		ft_is_p(args, tab);
	if (*format == 'u')
		ft_is_u(args, tab);
	if (*format == 'x' || *format == 'X')
		ft_is_x(args, tab, format);
	if (*format == '%')
		tab-> len += write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		args;
	t_list		tab;

	va_start(args, format);
	tab.len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_what_arg(args, &format[i + 1], &tab);
			i++;
		}
		else
			tab.len += write(1, &format[i], 1);
		if (!format[i])
		{
			tab.len += write(1, "(NULL)", 6);
			break ;
		}
		i++;
	}
	va_end(args);
	return (tab.len);
}
