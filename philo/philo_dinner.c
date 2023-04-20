/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:05:07 by dballini          #+#    #+#             */
/*   Updated: 2023/04/18 16:27:34 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  ft_sleeping()
{

}

void  ft_eating()
{
      pthread_mutex_lock(&mutex[MEAL]);

      pthread_mutex_unlock(&mutex[MEAL]);
}

void  ft_simulate_dinner(void *arg)
{
      t_philo     *self;

      self = (t_philo *) arg;
      if (self->philo_ID % 2 == 0)
      {}
}

int   ft_dinnner(t_param *params, t_philo *philos)
{
      int               i;
      pthread_t         *thread;

      thread = malloc (sizeof(pthread_t) * (size_t) params->n_philosophers);
      if (thread == NULL)
            return (FAILURE);
      i = -1;
      while (++i < params->n_philosophers)
      {
            if (pthread_create(&thread[i], 0, ft_simulate_dinner, (void *)&philos[i]))
            {
                  while (i--)
                        pthread_join(thread[i], NULL);
                  return ((void) free (thread), FAILURE);
            }
      }
      if (ft_)
      
}