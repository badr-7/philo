#ifndef PHILO_H
# define PHILO_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include <pthread.h>

typedef struct args
{
	int	number_philo;
	int	t_die;
    int	t_eat;
    int	t_sleep;
    int	must_eat;
}			t_args;

typedef struct philo
{
	int				index;
	int				eat_count;
	pthread_t		philo;
    pthread_mutex_t fork;
    struct philo	*next_philo;
	int				last_time_eat;
}			philo_data;

typedef struct tt
{
	philo_data	*philosofer;
	t_args		*args; 
	pthread_mutex_t	lock_print;
	char	dead;
}				all_data;


void pars(char **s);
void args_conv(char **s, t_args *a);
int	ft_atoi(const char	*str);
void creat_philos(all_data *a);
philo_data	*iniit2(void);

#endif