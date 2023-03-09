/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:10:01 by dballini          #+#    #+#             */
/*   Updated: 2023/03/09 16:18:01 by dballini         ###   ########.fr       */
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
			if ((data->map[i][j] == 'P' && p > 1) ||
				(data->map[i][j] == 'E' && e > 1))
				return (2);
		}
	}
	if (p == 0 || data->collectable == 0 || e == 0)
		return (1);
	return (0);
}

int	ft_borders_check(x_data *data)
{
	data->y = -1;
	data->x = -1;
	while (++data->x < data->xborder)
	{
		if (data->map[0][data->x] != '1' ||
			data->map[data->yborder - 1][data->x] != '1')
			return (1);
	}
	while (++data->y < data->yborder)
	{
		if (data->map[data->y][0] != '1' ||
			data->map[data->y][data->xborder - 1] != '1')
			return (1);
	}
	return (0);
}

int	ft_get_errors2(x_data *data)
{
	if (data->xborder <= data->yborder)
		return (5);
	if (ft_borders_check(data) == 1)
		return (4);
	if (ft_route_check(data) == 1)
		return (3);
	return (0);
}

void	ft_put_errors2(int error, x_data *data)
{
	if (error == 4)
	{
		write(1, "Error\n", 6);
		write(1, "Map has no walls around border\n", 32);
		ft_cleanclose(data);
	}
	else if (error == 5)
	{
		write(1, "Error\n", 6);
		write(1, "Map is not rectangular | lines are not equal\n", 46);
		ft_cleanclose(data);
	}
}

void	ft_put_errors(int error, x_data *data)
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
		write(1, "No route start to exit | collectable items cant be taken\n",
			59);
		ft_cleanclose(data);
	}
}
