/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:15:26 by dballini          #+#    #+#             */
/*   Updated: 2023/04/13 15:31:47 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_get_time(t_philo *philos)
{
	struct timeval current_time;
	long int	time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec + current_time.tv_usec;
	if (philos->params->start_time == 0)	
	{
		philos->params->start_time = time;
		return (0);
	}
	else
		philos->params->current_sec = time - philos->params->start_time;
	return (philos->params->current_sec);
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
	t_philo	philos;

	if (ac < 5 || ac > 6)
	{
		printf("Error\nNot enough arguments\n");
		return (1);
	}
	ft_init_timings(av, &philos);
	ft_init(&philos);
	for (int i = 0; i < 10; i++)
	{
		ft_print_status( &philos, "is eating");
		usleep(1000000);
	}
      return (0);
}