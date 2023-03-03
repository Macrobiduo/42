/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:04:53 by dballini          #+#    #+#             */
/*   Updated: 2023/03/03 12:07:35 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;

	len = 0;
	while (s[len])
		len++;
	str = (char *) malloc (len);
	if (!str)
		return (NULL);
	while (*s)
		*str++ = *s++;
	*str = '\0';
	return (str - len);
}

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

void	ft_floodmoves(int x, int y, char wall, char **flmap)
{
	if (flmap[y][x] != wall)
		flmap[y][x] = 'F';
	ft_floodmoves((x + 1), y, wall, flmap);
	ft_floodmoves((x - 1), y, wall, flmap);
	ft_floodmoves(x, (y + 1), wall, flmap);
	ft_floodmoves(x, (y - 1), wall, flmap);
}

int	ft_route_check(x_data *data)
{
	char	**flmap;
	int	i;

	flmap = malloc ((data->yborder - 1) * sizeof(char *));
	i = -1;
	while (++i < data->yborder)
		flmap[i] = ft_strdup(data->map[i]);
	data->flx = data->spritex;
	data->fly = data->spritey;
	ft_floodmoves(data->flx, data->fly, '1', flmap);
	return (0);
}

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
		write(1, "Map has no route from start to exit\n", 37);
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
