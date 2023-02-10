/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:26:09 by dballini          #+#    #+#             */
/*   Updated: 2023/02/10 17:37:21 by dballini         ###   ########.fr       */
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

void	ft_mandelbrot()
{

}

void	ft_calculate(x_data *data, t_data img)
{
	int		x;
	int		y;
	int		n;

	n = -1;
	x = -1;
	y = -1;
	while (y++ <= data->WindowsHeight)
	{
		data->c_im = data->MaxIm - y * data->Im_factor;
		while (x++ <= data->WindowsWidth)
		{
			data->c_re = data->MinRe + x * data->Re_factor;
			data->z_re = data->c_re;
			data->z_im = data->c_im;
			data->isInside = 1;
			while (n++ < data->MaxInteractions)
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
			}
			if (data->isInside == 1)
				my_mlx_pixel_put(&img, x, y, 0xFFFFFF);
		}
	}

}

void	ft_set_values(x_data *data)
{
	data->MinRe = -2;
	data->MaxRe = 1.0;
	data->MinIm = -1.2;
	data->WindowsHeight = 600;
	data->WindowsWidth = 600;
	data->MaxIm = data->MinIm + (data->MaxRe - data->MinRe) * data->WindowsHeight / data->WindowsWidth;
	data->Re_factor = (data->MaxRe - data->MinRe) / (data-> WindowsWidth - 1);
	data->Im_factor = (data->MaxIm - data->MinIm) / (data-> WindowsHeight - 1);
	data->MaxInteractions = 30; 
}

void	ft_start(x_data *data, t_data img)
{
	ft_calculate(data, img);
}

int		main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	x_data	data;
	int		i;
	int		j;

	j = 0;
	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "Fractol");
	img.img = mlx_new_image(mlx, 600, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	
	ft_set_values(&data);
	ft_start(&data, img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
