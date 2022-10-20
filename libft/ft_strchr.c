/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:08:29 by dballini          #+#    #+#             */
/*   Updated: 2022/10/10 15:29:32 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *) s + 1);
	return (NULL);
}
/*int	main()
{
	char	s[] = "eeeeeeeeeeeeeexeeeeeee";
	char	*t;
	int	p = 0;
	
	t = ft_strchr(s, p);
	printf("%s", t);
	return(0);
}*/
