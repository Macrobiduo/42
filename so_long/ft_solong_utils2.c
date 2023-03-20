/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:01:51 by dballini          #+#    #+#             */
/*   Updated: 2023/03/20 13:05:09 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(x_data *data)
{
	int		p;
	int		e;
	int		error;

	p = 0;
	e = 0;
	error = ft_get_errors2(data);
	ft_put_errors(error, data);
	error = ft_get_errors(data, p, e);
	ft_put_errors(error, data);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*p;

	if (nelem == 0 || elsize == 0)
	{
		p = malloc (1);
		return (p);
	}
	else
	{
		p = malloc (nelem * elsize);
		if (!p)
			return (NULL);
		ft_bzero(p, nelem * elsize);
		return (p);
	}
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	str = (char *) malloc (len + 1);
	if (!str)
		return (NULL);
	while (s[++i] && s[i] != '\n')
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
