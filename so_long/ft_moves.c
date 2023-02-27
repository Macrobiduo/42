/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:06:52 by dballini          #+#    #+#             */
/*   Updated: 2023/02/27 17:07:08 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_upmove(x_data *data)
{
	int		x;
	int		y;

	if (ft_move_check(data, 'w') == 0)
	{
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "sprite/WalkTiles.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->spritey -= 1;
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "sprite/WalkTileDX.xpm", &x, &y);
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
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "sprite/WalkTiles.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->spritey += 1;
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "sprite/WalkTileDX.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->moves++;
	}
}

void	ft_leftmove(x_data *data)
{
	int		x;
	int		y;

	if (ft_move_check(data, 'a') == 0)
	{
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "sprite/WalkTiles.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->spritex -= 1;
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "sprite/WalkTileDX.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->moves++;
	}
}

void	ft_rightmove(x_data *data)
{
	int		x;
	int		y;

	if (ft_move_check(data, 'd') == 0)
	{
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "sprite/WalkTiles.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->spritex += 1;
		data->img.img =  mlx_xpm_file_to_image(data->mlx, "sprite/WalkTileDX.xpm", &x, &y);
		x = data->spritex * 80;
		y = data->spritey * 80;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
		data->moves++;
	}
}
