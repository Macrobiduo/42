#include <stdio.h>
#include <stdlib.h>

long int	ft_atoi(const char *str)
{
	long int	result;
	int			i;
	int			sign;

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

int main(int argc, char *argv[])
{
    int     *nbr;
    int         i;

    i = 0;
    nbr = malloc ((sizeof(int)) * (argc - 1));
    while (i < argc)
    {
        nbr[i] = ft_atoi(argv[i]);
        printf("\"%d\", ", nbr[i]);
        i++;
    }
    
}