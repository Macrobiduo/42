/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:43:29 by dballini          #+#    #+#             */
/*   Updated: 2023/02/24 17:09:27 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_data {
	void		*img;
	void		*tempImg;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
}				t_data;

typedef struct f_data
{
	void			*mlx;
	void			*mlx_win;
	t_data		img;
	int			x;
	int			y;
	int			spritex;
	int			spritey;
	int			moves;
	char			map[10][20];
}		x_data;

#endif
