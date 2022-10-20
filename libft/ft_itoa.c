/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:41:02 by dballini          #+#    #+#             */
/*   Updated: 2022/10/14 13:41:02 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int     count(int n)
{
    int i;

    i = 0;
    if (n < 0)
        n *= -1;
    if (n == 0)
        i++;
    while (n > 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}

char *ft_itoa(int n)
{
    char    *p;
    int     i;

    i = count(n);
    if(n < 0)
    {
        p = (char *) malloc (i + 2);
        p[0] = '-';
        n *= -1;
        i++;
    }
    else
        p = (char *) malloc (i + 1);
    p[i] = '\0';
    while (n >= 0 && i >= 0)
    {
        i--;
        p[i] = (n % 10) + '0';
        n /=  10;
        if(n == 0)
            break;
    }
    return (p);
}
int main (){
    int n = 128;
    char *p = ft_itoa(n);
    printf("%s", p);
    return (0);
}