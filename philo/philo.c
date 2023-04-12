/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:15:26 by dballini          #+#    #+#             */
/*   Updated: 2023/04/12 17:25:30 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

long int	ft_get_time(t_param *params)
{
	struct timeval current_time;
	long int	time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec + current_time.tv_usec;
	if (params->start_time == 0)	
	{
		params->start_time = time;
		return (0);
	}
	else
		params->current_sec = time - params->start_time;
	return (params->current_sec);
}

void  ft_init_timings(char *av[], t_param *params)
{
      params->n_philosophers = ft_atoi(av[1]);
      params->time_to_die = ft_atoi(av[2]);
      params->time_to_eat = ft_atoi(av[3]);
      params->time_to_sleep = ft_atoi(av[4]);
      if (av[5])
            params->n_eating = ft_atoi(av[5]);
	else
		params->n_eating = 0;
}

void	ft_init(t_param *params)
{
	params->start_time = 0;
}

int   main(int ac, char *av[])
{
      t_param     params;
	ft_init_timings(av, &params);
	ft_init(&params);	
      return (0);
}