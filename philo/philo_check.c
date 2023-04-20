/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:40:44 by dballini          #+#    #+#             */
/*   Updated: 2023/04/20 16:08:27 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  ft_done(t_param *params)
{
      pthread_mutex_lock(&params->mutex[DONE]);
      params->done = 1;
      pthread_mutex_unlock(&params->mutex[DONE]);
}

void  ft_died(t_param *params)
{
      pthread_mutex_lock(&params->mutex[DIED]);
      params->died = 1;
      pthread_mutex_unlock(&params->mutex[DIED]);
}

int   ft_check_died(t_philo *philos)
{
      pthread_mutex_lock(&philos->params->mutex[DIED]);
      if (philos->params->died)
      {
            pthread_mutex_unlock(&philos->params->mutex[DIED]);
            return (1);
      }
      pthread_mutex_unlock(&philos->params->mutex[DIED]);
      return (0);
}

int   ft_check_done(t_philo *philos)
{
      pthread_mutex_lock(&philos->params->mutex[DONE]);
      if (philos->params->done)
      {
            pthread_mutex_unlock(&philos->params->mutex[DONE]);
            return (1);
      }
      pthread_mutex_unlock(&philos->params->mutex[DONE]);
      return (0);
}