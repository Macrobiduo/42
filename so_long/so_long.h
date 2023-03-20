/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:43:29 by dballini          #+#    #+#             */
/*   Updated: 2023/03/20 15:25:42 by dballini         ###   ########.fr       */
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

typedef struct s_data {
	void		*img;
	void		*tempimg;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
}				t_data;

typedef struct f_data
{
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
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	char		**map;
	char		*to_free;
}		t_dat;

void	ft_rightmove(t_dat *data);
void	ft_leftmove(t_dat *data);
void	ft_downmove(t_dat *data);
void	ft_upmove(t_dat *data);
void	ft_check_map(t_dat *data);
int		ft_errors(t_dat *data, int p, int e);
int		ft_move_check(t_dat *data, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_which_block(t_dat *data, char c);
void	ft_border_values(t_dat *data, char *str);
void	ft_initialize_map(int fd, t_dat *data);
void	ft_build_map(t_dat *data, int fd);
int		key_hook(int keyhook, t_dat *data);
void	ft_cleanclose(t_dat *data);
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_bzero(void *s, size_t n);
int		ft_get_errors(t_dat *data, int p, int e);
void	ft_put_errors(int error, t_dat *data);
void	ft_check_map(t_dat *data);
int		ft_route_check(t_dat *data);
void	ft_floodmoves(int x, int y, char wall, char **flmap);
int		ft_check_left(char **flmap, t_dat *data);
int		ft_move_check(t_dat *data, char c);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *destination, const char *source);
void	ft_put_errors2(int error, t_dat *data);
int		ft_get_errors2(t_dat *data);
void	ft_init(t_dat data, int fd);
void	ft_free_map(t_dat *data);
int		close_cross(t_dat *data);
void	ft_upgrade_values(t_dat *data);
#endif
