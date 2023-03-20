/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:06:52 by dballini          #+#    #+#             */
/*   Updated: 2023/03/20 15:26:15 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_upmove(t_dat *data)
{
	int		x;
	int		y;

	if (ft_move_check(data, 'w') == 0)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = mlx_xpm_file_to_image(data->mlx, "sprite/WalkTiles.xpm",
				&x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img,
			x, y);
		data->spritey -= 1;
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = mlx_xpm_file_to_image(data->mlx, "sprite/WalkTileP.xpm",
				&x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->moves++;
	}
}

void	ft_downmove(t_dat *data)
{
	int		x;
	int		y;

	if (ft_move_check(data, 's') == 0)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = mlx_xpm_file_to_image(data->mlx, "sprite/WalkTiles.xpm",
				&x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->spritey += 1;
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = mlx_xpm_file_to_image(data->mlx, "sprite/WalkTileP.xpm",
				&x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->moves++;
	}
}

void	ft_leftmove(t_dat *data)
{
	int		x;
	int		y;

	if (ft_move_check(data, 'a') == 0)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = mlx_xpm_file_to_image(data->mlx, "sprite/WalkTiles.xpm",
				&x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->spritex -= 1;
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = mlx_xpm_file_to_image(data->mlx, "sprite/WalkTileP.xpm",
				&x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img,
			x, y);
		data->moves++;
	}
}

void	ft_rightmove(t_dat *data)
{
	int		x;
	int		y;

	if (ft_move_check(data, 'd') == 0)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = mlx_xpm_file_to_image(data->mlx, "sprite/WalkTiles.xpm",
				&x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->spritex += 1;
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = mlx_xpm_file_to_image(data->mlx, "sprite/WalkTileP.xpm",
				&x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->moves++;
	}
}
