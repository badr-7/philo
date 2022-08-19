/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:26:09 by mel-hous          #+#    #+#             */
/*   Updated: 2022/08/19 10:43:36 by mel-hous         ###   ########.fr       */
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
	int				is_eating;
	int				eat_count;
	pthread_t		philo;
	pthread_mutex_t	fork;
	struct philo	*next_philo;
	int				last_time_eat;
	struct tt		*all_info;
}			t_philo_data;

typedef struct tt
{
	t_philo_data	*philosofer;
	t_args			*args;
	pthread_mutex_t	print;
	char			dead;
	unsigned int	starting_time;
}				t_all_data;

int				pars(char **s);
int				args_conv(char **s, t_args *a);
int				ft_atoi(const char	*str);
int				creat_forks(t_all_data *a);
void			lock_forks(t_philo_data *a);
unsigned int	actuel_time(void);
void			eating_time(t_philo_data *a);
void			*theory(void *arg);
void			ft_print(char *str, t_philo_data *a);
int				lmkadem(t_all_data *a);

#endif