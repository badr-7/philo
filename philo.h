#ifndef PHILO_H
# define PHILO_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include <pthread.h>
# include <sys/time.h>

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
	t_args			*arg;
	int				index;
	int				eat_count;
	pthread_t		philo;
    pthread_mutex_t fork;
    pthread_mutex_t eating;
    struct philo	*next_philo;
	int				last_time_eat;
	struct tt		*all_info;
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
void creat_forks(all_data *a, t_args *b);
philo_data	*iniit2(void);
void lock_forks(philo_data *a);
unsigned int actuel_time(void);
void eating_time(philo_data *a);


#endif