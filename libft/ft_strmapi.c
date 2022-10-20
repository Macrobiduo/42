/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:55:44 by dballini          #+#    #+#             */
/*   Updated: 2022/10/19 14:55:44 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;

	if (!s || !f)
		return (0);
	p = (char *) malloc (sizeof (char) * (ft_strlen(s) + 1));
	if (!p)
		return (0);
	i = 0;
	while (s[i])
	{
		p[i] = f(i, s[i]);
		++i;
	}
	p[i] = '\0';
	return (p);
}
