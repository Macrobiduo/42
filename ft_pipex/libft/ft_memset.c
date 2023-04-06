/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:53:26 by dballini          #+#    #+#             */
/*   Updated: 2022/10/04 15:53:28 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;
	int		i;

	p = s;
	i = 0;
	while (n > 0)
	{
		p[i] = c;
		n--;
		i++;
	}
	return (p);
}
/*int	main()
{
	char	s[] = "Questa stringa e una prova";
	ft_memset(s, '$', 15);
	printf("%s", s);
	return(0);
}*/
