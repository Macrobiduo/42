/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:15:31 by dballini          #+#    #+#             */
/*   Updated: 2023/04/20 17:08:49 by dballini         ###   ########.fr       */
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

void	ft_waiter(long int to_wait)
{
	usleep(to_wait);
}

void	ft_print_status(t_philo *philos, char *status)
{
	pthread_mutex_lock(&philos->params->mutex[PRINT]);
	if (((!ft_check_died(philos)) && (!ft_check_done(philos))))
		printf("[%ld]ms Philo %d %s\n", ft_get_time(philos), philos->philo_ID, status);
	pthread_mutex_unlock(&philos->params->mutex[PRINT]);

}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}