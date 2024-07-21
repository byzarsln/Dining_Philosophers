#include "philo.h"

long	ft_atol(const char *str)
{
	int	i;
	int sign;
	long result;

	i = 0;
	sign = 1;
	result = 0;

	if (!str[i])
		return (0);
	while(((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if(str[i] == '+')
		i++;
	while((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (sign * result);
}


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
