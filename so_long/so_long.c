/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:43:03 by dballini          #+#    #+#             */
/*   Updated: 2023/02/24 17:26:01 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_which_block(x_data *data, char c)
{
	int		x;
	int		y;

	// if (c == 'c')
	if (c == '1')
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "/nfs/homes/dballini/Documents/42/so_long/sprite/WallTile.xpm", &x, &y);
	if (c == '0')
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "/nfs/homes/dballini/Documents/42/so_long/sprite/WalkTiles.xpm", &x, &y);
	if (c == 'e')
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "/nfs/homes/dballini/Documents/42/so_long/sprite/EndTile.xpm", &x, &y);
	if (c == 'p')
	{
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "/nfs/homes/dballini/Documents/42/so_long/sprite/WalkTileDX.xpm", &x, &y);
		data->spritex = data->x;
		data->spritey = data->y;
	}
	x = data->x * 80;
	y = data->y * 80;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
}

void	ft_build_map(x_data *data, int fd)
{	
	int		check;
	char		*str;

	data->y = 0;
	while (data->y < 11)
	{
		data->x = 0;
		while (data->x < 21)
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
	if (data->map[nexty][nextx] == 49)
		return (1);
	return (0);
}

void	ft_upmove(x_data *data)
{
	int		x;
	int		y;

	if (ft_move_check(data, 'w') == 0)
	{
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "/nfs/homes/dballini/Documents/42/so_long/sprite/WalkTiles.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->spritey -= 1;
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "/nfs/homes/dballini/Documents/42/so_long/sprite/WalkTileDX.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->moves++;
	}
}

void	ft_downmove(x_data *data)
{
	int		x;
	int		y;

	if (ft_move_check(data, 's') == 0)
	{
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "/nfs/homes/dballini/Documents/42/so_long/sprite/WalkTiles.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->spritey += 1;
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "/nfs/homes/dballini/Documents/42/so_long/sprite/WalkTileDX.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
	}
}

void	ft_leftmove(x_data *data)
{
	int		x;
	int		y;

	if (ft_move_check(data, 'a') == 0)
	{
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "/nfs/homes/dballini/Documents/42/so_long/sprite/WalkTiles.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->spritex -= 1;
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "/nfs/homes/dballini/Documents/42/so_long/sprite/WalkTileDX.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
	}
}

void	ft_rightmove(x_data *data)
{
	int		x;
	int		y;

	if (ft_move_check(data, 'd') == 0)
	{
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "/nfs/homes/dballini/Documents/42/so_long/sprite/WalkTiles.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->spritex += 1;
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "/nfs/homes/dballini/Documents/42/so_long/sprite/WalkTileDX.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
	}
}

int	key_hook(int keyhook, x_data *data)
{
	data->moves = 0;
	if (keyhook == 119)
		ft_upmove(data);
	if (keyhook == 97)
		ft_leftmove(data);
	if (keyhook == 115)
		ft_downmove(data);
	if (keyhook == 100)
		ft_rightmove(data);	
	return (0);
}

int	main(int ac, char *av[])
{
	int		fd;
	x_data	data;
	if (ac < 2)
		return (1);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);	
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, 80 * 20, 80 * 10, "so_long");
		data.img.img = mlx_new_image(data.mlx, 80 * 20, 80 * 10);
		data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_lenght, &data.img.endian);
		mlx_key_hook(data.mlx_win, key_hook, &data);
		ft_build_map(&data, fd);
		mlx_loop(data.mlx);
		mlx_destroy_display(data.mlx_win);
		free(data.mlx);
	}
	return (0);
}