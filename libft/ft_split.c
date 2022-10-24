/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:38:17 by dballini          #+#    #+#             */
/*   Updated: 2022/10/10 15:38:17 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	count(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i);
}

int	leng(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			break ;
		i++;
		s++;
	}
	return (i + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		total;
	int		len;
	int		i;

	i = 0;
	total = count(s, c) + 1;
	arr = malloc (total * sizeof(char *));
	while (*s && i < total)
	{
		len = leng(s, c);
		arr[i] = malloc (len);
		while (*s != c && *s)
			*arr[i]++ = *s++;
		if (*s == c)
			s++;
		*arr[i] = '\0';
		arr[i] -= (len - 1);
		i++;
	}
	return (arr);
}
int     main() 
{
    char    **arr;
    char    *s = "  ";
    char    t = ' ';
    int     i = 0;
    int     divis = count(s, t);
    arr = ft_split(s, t);
   while(i < divis + 1)
   {    
        printf("%s\n", arr[i]);
        i++;
   }
    return (0);    
}
