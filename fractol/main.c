/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:26:09 by dballini          #+#    #+#             */
/*   Updated: 2023/02/13 17:37:53 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}

int		ft_mandelbrot(x_data *data, int n)
{
	while (n < data->MaxInteractions)
	{
		data->z_re2 = data->z_re * data->z_re;
		data->z_im2 = data->z_im * data->z_im;
		if (data->z_re2 + data->z_im2 > 4)
		{
			data->isInside = 0;
			break ;
		}
		data->z_im = 2 * data->z_re * data->z_im + data->c_im;
		data->z_re = data->z_re2 - data->z_im2 + data->c_re;
		n++;
	}
	return (n);
}

unsigned int	ft_get_color(int n, float Zn)
{
	unsigned char	rgba[4];
	unsigned int	color;
	float	continuous_index;

	if (Zn < 0)
		Zn *= -1;
	continuous_index = n + 1 - (log(2) / Zn) / log(2);
	rgba[0] = (unsigned char)(sin(0.016 * continuous_index + 4) * 230 + 25);
	rgba[1] = (unsigned char)(sin(0.013 * continuous_index + 2) * 230 + 25);
	rgba[2] = (unsigned char)(sin(0.01 * continuous_index + 1) * 230 + 25);
	color = (rgba[0] << 16) + (rgba[1] << 8) + (rgba[2] + 255);
	return (color);
}

void	ft_calculate(x_data *data, t_data img)
{
	int		x;
	int		y;
	int		n;

	y = -1;
	while (y++ < data->WindowsHeight)
	{
		x = -1;
		data->c_im = data->MaxIm - y * data->Im_factor;
		while (x++ < data->WindowsWidth)
		{
			data->c_re = data->MinRe + x * data->Re_factor;
			data->z_re = data->c_re;
			data->z_im = data->c_im;
			data->isInside = 1;
			n = 0;
			n = ft_mandelbrot(data, n);
			if (data->isInside)
				my_mlx_pixel_put(&img, x, y, 0x000000);
			else
				my_mlx_pixel_put(&img, x, y, ft_get_color(n, (data->z_re2 + data->z_im2)));
		}
	}
}

void	ft_set_values(x_data *data)
{
	data->MinRe = -2;
	data->MaxRe = 1.0;
	data->MinIm = -1.2;
	data->WindowsHeight = 500;
	data->WindowsWidth = 600;
	data->MaxIm = data->MinIm + (data->MaxRe - data->MinRe) * data->WindowsHeight / data->WindowsWidth;
	data->Re_factor = (data->MaxRe - data->MinRe) / (data->WindowsWidth - 1);
	data->Im_factor = (data->MaxIm - data->MinIm) / (data->WindowsHeight - 1);
	data->MaxInteractions = 30;
}

void	ft_start(x_data *data, t_data img)
{
	ft_calculate(data, img);
}

int	key_hook(int keyhook, x_data *data)
{
	if (!(data->mlx_win))
		return (0);
	if (keyhook == 65307)
		exit (0);
	if (keyhook == 116)
		
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	return (0);
}

int		main(void)
{
	x_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 600, 500, "Fractol");
	data.img.img = mlx_new_image(data.mlx, 600, 500);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_lenght, &data.img.endian);
	
	ft_set_values(&data);
	ft_start(&data, data.img);

	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop(data.mlx);
}
