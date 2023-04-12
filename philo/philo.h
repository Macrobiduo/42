/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:15:22 by dballini          #+#    #+#             */
/*   Updated: 2023/04/12 17:25:48 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_param
{
	long int	start_time;
	long int	current_sec;
	int		n_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		n_eating;         
}		t_param;

typedef struct s_philo
{

}		t_philo;
#endif