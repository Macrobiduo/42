/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:04:53 by dballini          #+#    #+#             */
/*   Updated: 2023/03/06 16:22:27 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_check(x_data *data, char c)
{
	int		nextx;
	int		nexty;

	nextx = data->spritex;
	nexty = data->spritey;
	if (c == 'w')
		nexty -= 1;
	if (c == 'a')
		nextx -= 1;
	if (c == 's')
		nexty += 1;
	if (c == 'd')
		nextx += 1;
	if (data->map[nexty][nextx] == 'C')
		data->collected++;
	if (data->map[nexty][nextx] == 'E' && data->collected < data->collectable)
		return (1);
	if (data->map[nexty][nextx] == '1')
		return (1);
	return (0);
}

int ft_check_left(char **flmap, x_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->yborder)
	{
		x = 0;
		while (x < data->xborder)
		{
			if (flmap[y][x] == 'E' || flmap[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_floodmoves(int x, int y, char wall, char **flmap)
{
	flmap[y][x] = '1';
	if (flmap[y][x + 1] != wall)
		ft_floodmoves((x + 1), y, wall, flmap);
	if (flmap[y][x - 1] != wall)
		ft_floodmoves((x - 1), y, wall, flmap);
	if (flmap[y + 1][x] != wall)
		ft_floodmoves(x, (y + 1), wall, flmap);
	if (flmap[y - 1][x] != wall)
		ft_floodmoves(x, (y - 1), wall, flmap);
}

void	ft_free_flmap(char **flmap, int limit)
{
	int		i;

	i = 0;
	while (i < limit)
	{
		free (flmap[i]);
		i++;
	}
	free (flmap);
	flmap = NULL;
}

int	ft_route_check(x_data *data)
{
	char	**flmap;
	int	i;

	flmap = malloc ((data->yborder) * sizeof(char *));
	i = -1;
	while (++i < data->yborder)
		flmap[i] = ft_strdup(data->map[i]);
	data->flx = data->spritex;
	data->fly = data->spritey;
	ft_floodmoves(data->flx, data->fly, '1', flmap);
	if (ft_check_left(flmap, data) == 1)
	{
		ft_free_flmap(flmap, data->yborder);
		return (1);
	}
	ft_free_flmap(flmap, data->yborder);
	return (0);
}
