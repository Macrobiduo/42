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

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int		len;
}	t_list;

/*---------------------------------------------------------------------------------------------*/

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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	ft_putstr(char *c) 
{
	int	i;

	i = 0;
	while(c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
}

void	ft_putchar(char c, t_list *tab) 
{
	tab->len += write(1, &c, 1);
}

void	ft_putnbr(int nb, t_list *tab) {
	if (nb < 0) {
		ft_putchar('-', tab);
		nb = -nb;
	}
	if (nb >= 10) {
		ft_putnbr(nb / 10, tab);
		nb = nb % 10;
	}
	if (nb < 10) ft_putchar(nb + 48, tab);
}

/*---------------------------------------------------------------------------------------------*/

void	ft_puthex(unsigned long num, t_list *tab, const char c)
{
	char	*hexa;
	int		i;

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

void	ft_is_c(va_list args, t_list *tab)
{
	int	c;

	c = va_arg(args, int);
	tab->len += write(1, &c, 1);
}

void	ft_is_s(va_list args, t_list *tab)
{
	char	*s;

	s = va_arg(args, char *);
	tab->len += ft_strlen(s);
	ft_putstr(s);
}

void	ft_is_d(va_list args, t_list *tab)
{
	int	d;

	d = va_arg(args, int);
	ft_putnbr(d, tab);
}

void	ft_is_p(va_list args, t_list *tab)
{
	unsigned long	p;

	p = va_arg(args, unsigned long);
	if (!p)
		tab->len += (1, "(nil)", 5);
	else
	{
		tab->len += write(1, "0x", 2);
		ft_puthex(p, tab, 'x');
	}	
}

void	ft_is_x(va_list args, t_list *tab, const char *format)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	ft_puthex(x, tab, *format);
}

void	ft_is_u(va_list args, t_list *tab)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);

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
		tab->len +=	write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_list	tab;
	int			i;

	va_start(args, format);
	tab.len = 0;
	i = 0;
	while(format[i])
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
			va_end(args);
			return (tab.len);
		}
		i++;
	}

	va_end(args);
	return (tab.len);
}

int	main () 
{
	char		*p = "WE bielo";
	int	n1;
	int	n2;
	int	numero = 3556;

	printf("\n");
	n1 = ft_printf("Occhio all %% puntatore %p %d", p, numero);
	printf("\n");
	n2 = printf("Occhio all %% puntatore %p %d", p, numero);
	printf("\n");
	printf("QUESTO è N1: %d, QUESTO è n2: %d", n1, n2);
	printf("\n");
	return (0);
}