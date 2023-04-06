/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:53:10 by dballini          #+#    #+#             */
/*   Updated: 2022/10/03 15:53:11 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int c)
{
	if (c < 127 && c >= 32)
		return (1);
	return (0);
}
/*int	main() 
{
	int	a = 123;
	int	i;
	
	i = ft_isprint(a);
	printf("%d", i);
	return(0);
}*/