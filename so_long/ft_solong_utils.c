/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:05:23 by dballini          #+#    #+#             */
/*   Updated: 2023/03/01 11:39:32 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar((char)(nbr % 10 + 48));
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (c < 0 || c > 255)
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*dst;
	int			i;
	int			j;

	i = -1;
	j = -1;
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dst && s1 && s2)
	{
		while (s1[++i])
			dst[i] = s1[i];
		while (s2[++j])
			dst[i + j] = s2[j];
		dst[i + j] = '\0';
	}
	else
		return (NULL);
	free (s1);
	free (s2);
	return (dst);
}
