/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:11:20 by mel-hous          #+#    #+#             */
/*   Updated: 2022/08/19 10:43:00 by mel-hous         ###   ########.fr       */
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
