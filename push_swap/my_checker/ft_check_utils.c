/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:44:46 by dballini          #+#    #+#             */
/*   Updated: 2023/02/22 14:45:48 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_errors(int argc, char **argv, int k)
{
	if (argc < 2 || check_arg(argv, argc) == 0)
	{
		if (k == 1)
			ft_free_argv(argv);
		write(1, "Error\n", 6);
		exit (0);
	}
}

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free (argv[i]);
		i++;
	}
	free(argv);
}

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (ft_strlen(src));
}
