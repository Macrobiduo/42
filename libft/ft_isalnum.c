/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:38:40 by dballini          #+#    #+#             */
/*   Updated: 2022/10/03 15:38:42 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	if (c > 47 && c < 58)
		return (1);
	return (0);
}
/*int	main() 
{
	int	a = 0;
	int	i;
	
	i = ft_isalnum(a);
	printf("%d", i);
	return(0);
}*/
