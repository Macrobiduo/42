/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:14:43 by dballini          #+#    #+#             */
/*   Updated: 2023/04/20 16:54:42 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo(t_param *params, t_philo **philos)
{
	pthread_mutex_t   *fork;
	int					i;

	fork = malloc (sizeof(pthread_mutex_t) * params->n_philosophers);
	if (fork == NULL)
		return (FAILURE);
	i = 0;
      while (i < params->n_philosophers)
            pthread_mutex_init (&fork[i++], NULL);
	i = 0;
	while (i < params->n_philosophers)
	{
		(*philos)[i].philo_ID = i + 1;
		(*philos)[i].lfork = i;
		if (i - 1 < 0)
			(*philos)[i].rfork = params->n_philosophers - 1;
		else
			(*philos)[i].rfork = i - 1;
		(*philos)[i].fork = fork;
		(*philos)[i].params = params;
		(*philos)[i].eaten_counter = 0;
		i++;
	}
	return (SUCCESS);
}

int	ft_init_mutex(t_param **params)
{
	pthread_mutex_t	*mutex;
	int					i;

	mutex = malloc (sizeof(pthread_mutex_t) * (size_t)M_NUM);
	if (mutex == NULL)
		return (FAILURE);
	i = 0;
	while (i < M_NUM)
		pthread_mutex_init(&mutex[i++], NULL);
	(*params)->mutex = mutex;
	return (SUCCESS);
}

int  ft_init_params(char *av[], t_param **params)
{
     	(*params)->start_time = 0;
      (*params)->n_philosophers = (int) ft_atoi(av[1]);
      (*params)->time_to_die = ft_atoi(av[2]);
      (*params)->time_to_eat = ft_atoi(av[3]);
      (*params)->time_to_sleep = ft_atoi(av[4]);
      (*params)->time_to_think = 0;
	(*params)->died = 0;
	(*params)->done = 0;
      if (((*params)->n_philosophers % 2) && (*params)->time_to_eat > (*params)->time_to_sleep)
            (*params)->time_to_think = 1 + ((*params)->time_to_eat - (*params)->time_to_sleep);
      if (av[5])
           (*params)->n_eating = (int) ft_atoi(av[5]);
	else
		(*params)->n_eating = -1;
      if (ft_init_mutex(params))
            return (FAILURE);
      return (SUCCESS);
      
}

int	ft_init(char *av[], t_philo **philos, t_param **params)
{
      (*params) = (t_param *) malloc (sizeof(t_param));
      if (!*params)
            return (FAILURE);
      (*params)->mutex = NULL;
      if (ft_init_params(av, params) != SUCCESS)
		return (FAILURE);
	*philos = (t_philo *) malloc (sizeof(t_philo) * (*params)->n_philosophers);
      if (!*philos)
            return (FAILURE);
	(*philos)->fork = NULL;
	if (ft_init_philo(*params, philos) != SUCCESS)
		return (FAILURE);
      return (SUCCESS);
}