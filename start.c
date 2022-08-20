/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:11:20 by mel-hous          #+#    #+#             */
/*   Updated: 2022/08/20 10:36:35 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	creat_forks(t_all_data *a)
{
	int	i;

	i = 0;
	a->philosofer = (t_philo_data *)malloc(sizeof(t_philo_data)
			* a->args->number_philo);
	while (i < a->args->number_philo)
	{
		a->philosofer[i].arg = a->args;
		a->philosofer[i].index = i + 1;
		if (pthread_mutex_init(&a->philosofer[i].fork, NULL) != 0)
			return (-1);
		if (i < a->args->number_philo - 1)
			a->philosofer[i].next_philo = &a->philosofer[i + 1];
		i++;
	}
	a->philosofer[i - 1].next_philo = &a->philosofer[0];
	a->starting_time = actuel_time();
	return (0);
}

t_args	*iniit(void)
{
	t_args	*a;

	a = (t_args *)malloc(sizeof(t_args));
	a->number_philo = 0;
	a->t_die = 0;
	a->t_eat = 0;
	a->t_sleep = 0;
	a->must_eat = 0;
	return (a);
}

int	creat_treads(t_all_data *a, int chosen_ones)
{
	int	i;

	i = chosen_ones;
	while (i < a->args->number_philo)
	{
		a->philosofer[i].all_info = a;
		a->philosofer[i].eat_count = 0;
		a->philosofer[i].is_eating = 0;
		a->philosofer[i].last_time_eat = actuel_time();
		if (pthread_create(&a->philosofer[i].philo, NULL, theory,
				(void *)&a->philosofer[i]) != 0)
			return (-1);
		if (pthread_detach(a->philosofer[i].philo) != 0)
			return (-1);
		i += 2;
	}
	return (0);
}

int	ft_run(t_all_data *a)
{
	if (creat_treads(a, 0) == -1)
		return (-1);
	usleep(100);
	if (creat_treads(a, 1) == -1)
		return (-1);
	return (0);
}
