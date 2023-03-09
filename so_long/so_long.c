/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:43:03 by dballini          #+#    #+#             */
/*   Updated: 2023/03/09 16:42:22 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(x_data *data)
{
	int	i;

	i = 0;
	while (i < data->yborder)
	{
		free (data->map[i]);
		i++;
	}
	free (data->map);
	data->map = NULL;
}

void	ft_cleanclose(x_data *data)
{
	if (data->map)
		ft_free_map (data);
	if (data->mlx)
		mlx_destroy_window(data->mlx, data->mlx_win);
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
	if (data->map[data->spritey][data->spritex] ==
		'E' && data->collected == data->collectable)
		ft_cleanclose(data);
	return (0);
}

void	ft_init(x_data data, int fd)
{
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 80 * data.xborder,
			80 * data.yborder,
			"so_long");
	data.img.img = mlx_new_image(data.mlx, 80 * data.xborder,
			80 * data.yborder);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
			&data.img.line_lenght, &data.img.endian);
	mlx_destroy_image(data.mlx, data.img.img);
	ft_build_map(&data, fd);
	ft_check_map(&data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop(data.mlx);
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
		ft_init(data, fd);
	}
	return (0);
}
