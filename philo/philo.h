/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:15:22 by dballini          #+#    #+#             */
/*   Updated: 2023/04/26 17:25:51 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_param
{
	long int		start_time;
	long int		current_sec;
	int		n_philosophers;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	int		n_eating;
	int		died;
	int		done;
	pthread_mutex_t	*mutex;
}		t_param;

typedef struct s_philo
{
	unsigned long		last_meal;
	int		eaten_counter;
	int		lfork;
	int		rfork;
	int		philo_ID;
	pthread_mutex_t	*fork;
	t_param	*params;
}		t_philo;

typedef enum e_mutexes
{
	PRINT,
	MEAL,
	DONE,
	DIED,
	M_NUM
}	t_mutexes;

typedef enum s_exit
{
	SUCCESS,
	FAILURE
}	t_exit;


void	ft_print_status(t_philo *philos, char *status);
long int	ft_get_time(t_philo *philos);
long int	ft_atoi(const char *str);
int	ft_min(int a, int b);
int	ft_max(int a, int b);

int  ft_init_params(char *av[], t_param **params);
int	ft_init(char *av[], t_philo **philos, t_param **params);
int	ft_init_mutex(t_param **params);
int	ft_init_philos(t_philo **philos, t_param *params);


void  ft_free_mem(t_param *params, t_philo *philos);
void	ft_waiter(long int to_wait);
void  ft_destroy_mutex(t_philo *philos, t_param *params);
int   ft_check_done(t_philo *philos);
int   ft_check_died(t_philo *philos);
void  ft_died(t_param *params);
void  ft_done(t_param *params);
int   ft_dinnner(t_param *params, t_philo *philos);
void  *ft_simulate_dinner(void *arg);



#endif