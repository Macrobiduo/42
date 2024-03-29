/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:10:40 by dballini          #+#    #+#             */
/*   Updated: 2022/10/07 01:10:40 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	start(char const *s1, char const *set)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (*s1)
	{
		while (*set != *s1 && *set)
		{
			i++;
			set++;
		}
		if (*set == '\0')
			break ;
		s1++;
		set -= i;
		i = 0;
		count++;
	}
	return (count);
}

int	end(char const *s1, char const *set)
{
	int		i;
	int		count;
	int		len;

	len = ft_strlen (s1) - 1;
	s1 += len;
	count = 0;
	while (len > 0)
	{
		i = 0;
		while (*set != *(s1) && *set)
		{
			i++;
			set++;
		}
		if (*set == '\0')
			break ;
		s1--;
		set -= i;
		count++;
		len--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		len;
	int		i;
	int		st;
	int		en;

	i = 0;
	len = ft_strlen(s1);
	st = start(s1, set);
	en = end(s1, set);
	if (st + en > len)
	{
		p = (char *)malloc(1);
	}
	else
		p = (char *)malloc(len - (st + en) + 1);
	if (!p)
		return (NULL);
	while (i < (len - en - st))
	{
		p[i] = s1[i + st];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*int    main()
{
    char    *p;
    char const *s = "  \t \t \n   \n\n\n\t";
    char const *set = " \n\t";

    printf("%d\n", start(s, set));
    printf("%d\n", end(s, set));
    p = ft_strtrim(s, set);
    printf("%s\n", p);
}*/
