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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = len;
	p = (char *) malloc (sizeof (char) * (int)len);
	if (p == 0)
		return (NULL);
	while (i-- > 0 && s)
		*p++ = *(s++ + start);
	return (p - len);
}
/*int     main()
{
    char    s[] = "Stringa di prova";
    char    *p;

    p = ft_substr(s, 3, 7);
    printf("%s\n", p);
    return 0;
}*/
