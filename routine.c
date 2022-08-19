/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:31:32 by mel-hous          #+#    #+#             */
/*   Updated: 2022/08/18 15:21:18 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_philo_data *a)
{
	pthread_mutex_lock(&a->fork);
	ft_print("take a fork", a);
	pthread_mutex_lock(&a->next_philo->fork);
	ft_print("take a fork", a);
}

void	eating_time(t_philo_data *a)
{
	a->is_eating = 1;
	ft_print("is eating", a);
	a->last_time_eat = actuel_time();
	usleep(a->arg->t_eat * 1000);
	a->is_eating = 0;
	if (a->arg->must_eat != 0)
		a->eat_count += 1;
	pthread_mutex_unlock(&a->fork);
	pthread_mutex_unlock(&a->next_philo->fork);
}

void	sleeping_time(t_philo_data	*a)
{
	ft_print("is sleeping", a);
	usleep(a->arg->t_sleep * 1000);
	ft_print("is thinking", a);
}

void	*theory(void *arg)
{
	t_philo_data	*a;

	a = (t_philo_data *)arg;
	while (1)
	{
		lock_forks(a);
		eating_time(a);
		sleeping_time(a);
	}
}
