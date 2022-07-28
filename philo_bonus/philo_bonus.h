/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:34:05 by mel-hous          #+#    #+#             */
/*   Updated: 2022/07/28 14:35:59 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

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

int	pars(char **s);

#endif