/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapbuild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:07:39 by dballini          #+#    #+#             */
/*   Updated: 2023/03/03 00:21:23 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_which_block(x_data *data, char c)
{
	int		x;
	int		y;

	if (c == 'C')
		data->img.img = mlx_xpm_file_to_image(data->mlx, "sprite/Collectable.xpm", &x, &y);
	if (c == '1')
		data->img.img = mlx_xpm_file_to_image(data->mlx, "sprite/WallTile.xpm", &x, &y);
	if (c == '0')
		data->img.img = mlx_xpm_file_to_image(data->mlx, "sprite/WalkTiles.xpm", &x, &y);
	if (c == 'E')
		data->img.img = mlx_xpm_file_to_image(data->mlx, "sprite/EndTile.xpm", &x, &y);
	if (c == 'P')
	{
		data->img.img = mlx_xpm_file_to_image(data->mlx, "sprite/WalkTileDX.xpm", &x, &y);
		data->spritex = data->x;
		data->spritey = data->y;
	}
	x = data->x * 80;
	y = data->y * 80;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
}

void	ft_border_values(x_data *data, char *str)
{
	int	xlen;
	int	ylen;

	xlen = 0;
	ylen = 0;
	while (*str)
	{
		if (*str == '\n')
		{
			str++;
			ylen++;
			data->xborder = xlen;
			xlen = 0;
		}
		xlen++;
		str++;
	}
	data->yborder = ylen + 1;
}

void	ft_initialize_map(int fd, x_data *data)
{
	int	check;
	char	*str;
	char	*red;
	int		i;

	i = - 1;
	data->moves = 0;
	data->collected = 0;
	data->collectable = 0;
	str = ft_calloc (1, 1);
	while (1)
	{
		red = ft_calloc (2, 1);
		check = read (fd, red, 1);
		str = ft_strjoin(str, red);
		if (check == 0)
			break ;
	}
	ft_border_values(data, str);
	data->map = malloc (data->yborder * sizeof(char *));
	while (++i < data->yborder)
		data->map[i] = malloc (data->xborder * sizeof(char));
	free (str);
}

void	ft_build_map(x_data *data, int fd)
{
	char		*str;

	data->y = 0;
	while (data->y < data->yborder)
	{
		data->x = 0;
		while (data->x <= data->xborder)
		{
			str = ft_calloc(2, 1);
			read(fd, str, 1);
			ft_which_block(data, str[0]);
			data->map[data->y][data->x] = str[0];
			free (str);
			data->x++;
		}
		data->y++;
	}
}
