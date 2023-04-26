/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:15:26 by dballini          #+#    #+#             */
/*   Updated: 2023/04/26 16:33:21 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_get_time(t_philo *philos)
{
	struct timeval current_time;
	long int	t;
	long int	s;
	long int	ret;

	if (gettimeofday(&current_time, NULL) == -1)
		printf("Error getting time\n");
	t = current_time.tv_sec * 1000;
	s = current_time.tv_usec / 1000;
	if (philos->params->start_time == 0)
	{
		philos->params->start_time = t + s;
		return (0);
	}
	else
		ret = t + s - philos->params->start_time;
	return (ret);	
}

/* 
#0	number_of_philosophers 
#1	time_to_die 
#2	time_to_eat
#3	time_to_sleep
#4	[number_of_times_each_philosopher_must_eat]
*/

int   main(int ac, char *av[])
{
	t_philo	*philos;
	t_param	*params;

	philos = NULL;
	params = NULL;
	if (ac < 5 || ac > 6)
	{
		printf("Error\nNot enough arguments\n");
		return ((void)ft_free_mem(params, philos), 1);
	}
	if (ft_init(av, &philos, &params) != SUCCESS)
		return ((void)ft_free_mem(params, philos), 1);
	if (ft_dinnner(params, philos) != SUCCESS)
		return ((void)ft_free_mem(params, philos), 1);
      return ((void)ft_free_mem(params, philos), 0);
}