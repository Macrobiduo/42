/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:16:07 by dballini          #+#    #+#             */
/*   Updated: 2023/03/20 15:27:07 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_upgrade_values(t_dat *data)
{
	data->xborder = data->x;
	data->y++;
	data->x = 0;
}

int	close_cross(t_dat *data)
{
	ft_cleanclose(data);
	return (0);
}
