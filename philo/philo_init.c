/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:14:43 by dballini          #+#    #+#             */
/*   Updated: 2023/04/13 15:46:04 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  ft_init_timings(char *av[], t_philo *philos)
{
      philos->params->n_philosophers = (int) ft_atoi(av[1]);
      philos->params->time_to_die = ft_atoi(av[2]);
      philos->params->time_to_eat = ft_atoi(av[3]);
      philos->params->time_to_sleep = ft_atoi(av[4]);
      if (av[5])
            philos->params->n_eating = (int) ft_atoi(av[5]);
	else
		philos->params->n_eating = 0;
}

void	ft_init(t_philo *philos)
{
	philos->params->start_time = 0;

}