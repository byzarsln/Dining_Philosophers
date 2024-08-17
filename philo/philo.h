/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:20:37 by beyarsla          #+#    #+#             */
/*   Updated: 2024/08/16 13:43:06 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h> 
# include <sys/time.h>
# include <unistd.h> 

# define ERR_ARG "Error: Invalid args."
# define ERR_INIT "Error: Init failed."

# define PHILO_MAX 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				chair_no;
	size_t			time_of_last_meal;
	int				eat_count;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	last_meal_mutex;
	struct s_data	*t_data;
}					t_philo;

typedef struct s_data
{
	int				number_of_philo;
	size_t			timo_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nbr_of_times_eat;
	size_t			start_time;
	t_philo			philo[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];
	pthread_mutex_t	message;
	pthread_mutex_t	end_mutex;
	bool			end;
}					t_data;

int					init_all(t_data *data, int argc, char **argv);
void				*routine(void *arg);
int					philo_start(t_data *data);
long				ft_atol(char *str);
int					ft_isdigit(int c);
size_t				get_current_time(void);
void				ft_usleep(size_t ms);
int					ft_print(t_philo *philo, char *state);
void				dead_check(t_data *data);
void				dead_calc(t_data *data);
void				thinking(t_philo *philo);
void				sleeping(t_philo *philo);
void				clean_all(t_data *data);
void				even_eating(t_philo *philo);
void				odd_eating(t_philo *philo);

#endif
