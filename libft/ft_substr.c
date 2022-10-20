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

	i = len;
	if (start > (unsigned int)strlen(s))
		len = 0;
	p = (char *) malloc ((sizeof (char) * (int)len) + 1);
	if (p == 0)
		return (NULL);
	while (i-- > 0 && s)
		*p++ = *(s++ + start);
	*p = '\0';
	return (p - len);
}
/*int     main()
{
    char    s[] = "lorem ipsum dolor sit amet";
    char    *p;

    p = ft_substr(s, 400, 20);
    printf("%s\n", p);
    return 0;
}*/