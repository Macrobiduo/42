/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:43:03 by dballini          #+#    #+#             */
/*   Updated: 2023/02/27 17:08:41 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cleanclose(x_data *data)
{
	free(data->mlx);
	exit (0);
}

int	key_hook(int keyhook, x_data *data)
{
	if (keyhook == 65307)
		ft_cleanclose(data);
	if (keyhook == 119)
		ft_upmove(data);
	if (keyhook == 97)
		ft_leftmove(data);
	if (keyhook == 115)
		ft_downmove(data);
	if (keyhook == 100)
		ft_rightmove(data);
	ft_putnbr(data->moves);
	write (1, "\n", 1);
	if (data->map[data->spritey][data->spritex] == 'E' && data->collected == 1)
		ft_cleanclose(data);
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
		ft_initialize_map(fd, &data);
		close(fd);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, 80 * data.xborder, 80 * data.yborder, "so_long");
		data.img.img = mlx_new_image(data.mlx, 80 * data.xborder, 80 * data.yborder);
		data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_lenght, &data.img.endian);
		ft_build_map(&data, fd);
		ft_check_map(&data);
		mlx_key_hook(data.mlx_win, key_hook, &data);
		mlx_loop(data.mlx);
		mlx_destroy_display(data.mlx_win);
	}
	return (0);
}