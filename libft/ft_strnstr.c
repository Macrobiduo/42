/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:03:05 by dballini          #+#    #+#             */
/*   Updated: 2022/10/05 18:03:07 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*find(const char *gig, const char *lil, size_t len)
{
	char	*strt;

	strt = (char *)gig;
	while (*gig++ == *lil++ && len > 0)
	{
		if (*lil == '\0')
			return (strt);
		len--;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*start;

	start = NULL;
	if (*little == '\0')
		return ((char *)big);
	while (len && *big && *little)
	{
		if (*big == *little)
			start = find(big, little, len);
		if (start != NULL)
			return (start);
		big++;
		len--;
	}
	return (start);
}
/*int	main()
{
	char	b[] = "lorem ipsum dolor sit amet";
	char	l[] = "dolor";
	char	*p;
	
	p = ft_strnstr(b, l, 15);
	printf("%s", p);
	return(0);
}*/
