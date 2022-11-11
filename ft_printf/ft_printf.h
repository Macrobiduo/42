/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:43:04 by dballini          #+#    #+#             */
/*   Updated: 2022/11/10 16:43:04 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct x_list
{
	int		len;
}	t_p;

void	ft_putstr(char *c);
void	ft_putchar(char c, t_p *tab);
void	ft_putnbr(int nb, t_p *tab);
void	ft_putunbr(unsigned int nb, t_p *tab);
void	ft_puthex(unsigned long num, t_p *tab, const char c);
void	ft_is_c(va_list args, t_p *tab);
void	ft_is_s(va_list args, t_p *tab);
void	ft_is_d(va_list args, t_p *tab);
void	ft_is_p(va_list args, t_p *tab);
void	ft_is_x(va_list args, t_p *tab, const char *format);
void	ft_is_u(va_list args, t_p *tab);
void	ft_what_arg(va_list args, const char *format, t_p *tab);
int		ft_printf(const char *format, ...);
int		ft_strlen(const char *s);
int		ft_count(long int n);
char	*ft_divide(char *p, long int num, int i);
char	*ft_itoa(int n);

#endif