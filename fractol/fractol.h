/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:32:47 by dballini          #+#    #+#             */
/*   Updated: 2023/02/10 17:19:16 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	s_data {
	void		*img;
	char		*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

typedef struct f_data
{
	float	        MinRe;
	float	        MaxRe;
	float	        MinIm;
	float	        MaxIm;
	float	        Re_factor;
	float	        Im_factor;
    int             WindowsHeight;
    int             WindowsWidth;
	int	            MaxInteractions;
    float			c_im;
	float			c_re;
    float           z_im;
    float           z_re;
    float           z_re2;
    float           z_im2;
    int            isInside;
}       x_data;

#endif