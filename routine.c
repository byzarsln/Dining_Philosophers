#include "philo.h"

void	routine(t_data *data)
{
	return(EXIT_SUCCESS);
}

int	philo_start(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->number_of_philo)
	{
		pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]);
		i++;
	}
	i = 0;
	while(i < data->number_of_philo)
	{
		pthread_join(&data->philo[i].thread, NULL);//eşit değilse sıfıra kontrolü koy
		i++;
	}
}
