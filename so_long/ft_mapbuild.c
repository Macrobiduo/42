/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapbuild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:07:39 by dballini          #+#    #+#             */
/*   Updated: 2023/02/27 17:08:45 by dballini         ###   ########.fr       */
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
	data->collected = 0;
	while (*str)
	{
		xlen++;
		if (*str == '\n')
		{
			ylen++;
			data->xborder = xlen - 1;
			xlen = 0;
		}
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
	str = malloc (1);
	while (1)
	{
		red = malloc (2);
		red[1] = '\0';
		check = read (fd, red, 1);
		str = ft_strjoin(str, red);
		if (check == 0)
			break ;
	}
	ft_border_values(data, str);
	data->map = malloc (data->yborder * sizeof(char *));
	while (++i <= data->yborder)
		data->map[i] = malloc (data->xborder * sizeof(char));
	free (str);
}

void	ft_build_map(x_data *data, int fd)
{	
	int			check;
	char		*str;

	data->y = 0;
	while (data->y <= data->yborder)
	{
		data->x = 0;
		while (data->x <= data->xborder)
		{
			str = malloc (1);
			check = read(fd, str, 1);
			ft_which_block(data, str[0]);
			data->map[data->y][data->x] = str[0];
			free (str);
			data->x++;
		}
		data->y++;
	}
}
