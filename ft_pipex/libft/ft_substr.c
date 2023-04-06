/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:20:48 by dballini          #+#    #+#             */
/*   Updated: 2022/10/06 18:20:48 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (len > (size_t)ft_strlen(s))
		len = ft_strlen(s);
	if (start > (unsigned int)ft_strlen(s))
	{
		start = ft_strlen(s);
		len = 0;
	}
	p = malloc (len + 1);
	if (!p)
		return (NULL);
	while (i < len && s[i + start])
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*int     main()
{
    char    s[] = "lorem ipsum dolor sit amet";
    char    *p;

    p = ft_substr(s, 400, 20);
    printf("%s\n", p);
    return 0;
}*/
