/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:43:29 by dballini          #+#    #+#             */
/*   Updated: 2023/03/06 16:22:19 by dballini         ###   ########.fr       */
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
	int			xborder;
	int			yborder;
	int			collected;
	int			collectable;
	int			flx;
	int			fly;
	char			**map;
}		x_data;

void	ft_rightmove(x_data *data);
void	ft_leftmove(x_data *data);
void	ft_downmove(x_data *data);
void	ft_upmove(x_data *data);
void	ft_check_map(x_data *data);
int		ft_errors(x_data *data, int p, int e);
int		ft_move_check(x_data *data, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_which_block(x_data *data, char c);
void	ft_border_values(x_data *data, char *str);
void	ft_initialize_map(int fd, x_data *data);
void	ft_build_map(x_data *data, int fd);
int		key_hook(int keyhook, x_data *data);
void	ft_cleanclose(x_data *data);
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_bzero(void *s, size_t n);
int		ft_get_errors(x_data *data, int p, int e);
void	ft_put_errors(int error, x_data *data);
void	ft_check_map(x_data *data);
int		ft_route_check(x_data *data);
void	ft_floodmoves(int x, int y, char wall, char **flmap);
int 		ft_check_left(char **flmap, x_data *data);
int	ft_move_check(x_data *data, char c);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char* destination, const char* source);
#endif
