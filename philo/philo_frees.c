/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_frees.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:04:15 by dballini          #+#    #+#             */
/*   Updated: 2023/04/18 16:25:37 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  ft_free_mem(t_param *params, t_philo *philos)
{
      if (params && params->mutex)
            free(params->mutex);
      if (params)
            free (params);
      if (philos && philos->fork)
            free (philos->fork);
      if (philos)
            free (philos);
}

static void ft_destroy_mutex(t_philo *philos, t_param *params)
{
      int   i;

      i = 0;
      while (i < philos->params->n_philosophers)
            pthread_mutex_destroy(&philos->fork[i++]);
      i = 0;
      while (i < M_NUM)
            pthread_mutex_destroy(&params->mutex[i++]);
}