/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:05:07 by dballini          #+#    #+#             */
/*   Updated: 2023/04/20 17:11:52 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int  ft_finish_eating(t_philo *self)
{
      ft_print_status(self, "is sleeping");
      pthread_mutex_unlock(&self->fork[ft_min(self->lfork, self->rfork)]);
      pthread_mutex_unlock(&self->fork[ft_max(self->lfork, self->rfork)]);
      ft_waiter(self->params->time_to_sleep);
      return (SUCCESS);
}

static int  ft_start_eating(t_philo *self)
{
      pthread_mutex_lock(&self->fork[ft_min(self->lfork, self->rfork)]);
      ft_print_status(self, "has taken a fork");
      if (self->lfork == self->rfork)
      {
            pthread_mutex_unlock(&self->fork[ft_min(self->lfork, self->rfork)]);
            return (FAILURE);
      }
      pthread_mutex_lock(&self->fork[ft_max(self->lfork, self->rfork)]);
      ft_print_status(self, "has taken a fork");
      ft_print_status(self, "is eating");
      return (SUCCESS);
}

static int  ft_eating(t_philo *self)
{
      if (ft_start_eating(self) != SUCCESS)
            return (FAILURE);
      pthread_mutex_lock(&self->params->mutex[MEAL]);
      self->last_meal = ft_get_time(self);
      self->eaten_counter++;
      pthread_mutex_unlock(&self->params->mutex[MEAL]);
      if (ft_check_done(self))
      {
            ft_finish_eating(self);
            return (FAILURE);
      }
      ft_waiter(self->params->time_to_eat);
      ft_finish_eating(self);
      return (SUCCESS);
}

void  *ft_simulate_dinner(void *arg)
{
      t_philo     *self;

      self = (t_philo *) arg;
      if (self->philo_ID % 2 == 0)
      {
            ft_print_status(self, "is thinking");
            ft_waiter(self->params->time_to_eat);
      }
      while (1)
      {
            if (ft_check_died(self))
                  break ;
            if (ft_eating(self) != SUCCESS)
                  break ;
            ft_print_status(self, "is thinking");
            ft_waiter(self->params->time_to_think);
      }
      return (NULL);
}

static int	ft_all_done(t_philo *philos, t_param *params)
{
	int		i;
	int		done;
	int		meal_count;

	if (params->n_eating == -1)
		return (0);
	i = -1;
	done = -1;
	while (++i < params->n_philosophers)
	{
		pthread_mutex_lock(&philos->params->mutex[MEAL]);
		meal_count = philos[i].eaten_counter;
		pthread_mutex_unlock(&philos->params->mutex[MEAL]);
		if (meal_count >= params->n_eating)
			if (++done == params->n_philosophers - 1)
				return (1);
		usleep(50);
	}
	return (0);
}

static int	ft_watch(t_philo *philos, t_param *params)
{
	int			i;
	long int	last_meal;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&params->mutex[MEAL]);
		last_meal = philos[i].last_meal;
		pthread_mutex_unlock(&params->mutex[MEAL]);
		if (last_meal && ft_all_done(philos, params))
		{
			ft_done(params);
			break ;
		}
		if (last_meal && ft_get_time(&philos[i]) - last_meal > params->time_to_die)
		{
			ft_print_status(&philos[i], "died");
			ft_died(params);
			break ;
		}
		i = (i + 1) & params->n_philosophers;
		usleep(200);
	}
	return (SUCCESS);
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
	if (ft_watch(philos, params) != SUCCESS)
		return ((void)ft_destroy_mutex(philos, params), (void)free(thread), FAILURE);
	i = -1;
	while (++i < params->n_philosophers)
		if (pthread_join(thread[i], NULL))
			return (FAILURE);
	return ((void)ft_destroy_mutex(philos, params), (void)free(thread), SUCCESS);
}
