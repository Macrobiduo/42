/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:10:01 by dballini          #+#    #+#             */
/*   Updated: 2023/03/03 13:13:15 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_errors(x_data *data, int p, int e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->yborder)
	{
		j = -1;
		while (++j < data->xborder)
		{
			if (data->map[i][j] == 'P')
				p++;
			if (data->map[i][j] == 'E')
				e++;
			if (data->map[i][j] == 'C')
				data->collectable++;
			if ((data->map[i][j] == 'P' && p > 1) || (data->map[i][j] == 'E' && e > 1))
				return (2);
		}
	}
	if (p == 0 || data->collectable == 0 || e == 0)
		return (1);
	if (ft_route_check(data) == 1)
		return (3);
	return (0);
}

void ft_put_errors(int error, x_data *data)
{
	if (error == 1)
	{
		write(1, "Error\n", 6);
		write(1, "Missing start, exit or collectable positions in map\n", 53);
		ft_cleanclose(data);
	}
	else if (error == 2)
	{
		write(1, "Error\n", 6);
		write(1, "Too many start/exit positions in map\n", 38);
		ft_cleanclose(data);
	}
	else if (error == 3)
	{
		write(1, "Error\n", 6);
		write(1, "Map has no route from start to exit or collectable items cant be all taken\n", 76);
		ft_cleanclose(data);
	}
}

void	ft_check_map(x_data *data)
{
	int		p;
	int		e;
	int		error;

	p = 0;
	e = 0;
	error = ft_get_errors(data, p, e);
	ft_put_errors(error, data);	
}
