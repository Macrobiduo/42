/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:45:16 by dballini          #+#    #+#             */
/*   Updated: 2022/05/23 16:45:17 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*int	main()
{
	int	n;
	n = ft_atoi("        ---+++234,985");
	printf("%d", n);
	return (0);
}*/
