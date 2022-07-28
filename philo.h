/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:26:09 by mel-hous          #+#    #+#             */
/*   Updated: 2022/07/28 15:17:59 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	pthread_mutex_t	fork;
	pthread_mutex_t	eating;
	struct philo	*next_philo;
	int				last_time_eat;
	struct tt		*all_info;
}			t_philo_data;

typedef struct tt
{
	t_philo_data	*philosofer;
	t_args			*args;
	pthread_mutex_t	lock_print;
	char			dead;
	unsigned int	starting_time;
	int				philo_dead;
}				t_all_data;

int				pars(char **s);
void			args_conv(char **s, t_args *a);
int				ft_atoi(const char	*str);
void			creat_forks(t_all_data *a, t_args *b);
t_philo_data	*iniit2(void);
void			lock_forks(t_philo_data *a);
unsigned int	actuel_time(void);
void			eating_time(t_philo_data *a);
void			*theory(void *arg);
void			ft_print(char *str, t_philo_data *a);
int				lmkadem(t_all_data *a);

#endif