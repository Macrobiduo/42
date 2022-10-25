/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:50:13 by dballini          #+#    #+#             */
/*   Updated: 2022/10/05 16:50:14 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			p = s;
		s++;
	}
	if (p == NULL && c != '\0')
		return (NULL);
	if (c == '\0')
		return ((char *)s);
	else
		return ((char *)p);
}
