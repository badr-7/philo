/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdead.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:22:26 by mel-hous          #+#    #+#             */
/*   Updated: 2022/08/20 09:54:01 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checker(t_all_data *a, int i, int j)
{
	if (actuel_time() - a->philosofer[i].last_time_eat
		>= (unsigned int)a->philosofer[i].arg->t_die)
	{
		if (a->philosofer[i].is_eating == 1)
			return (0);
		pthread_mutex_lock(&a->philosofer[i].eat_lock);
		pthread_mutex_lock(&a->print);
		ft_print("is dead", &a->philosofer[i]);
		return (-1);
	}
	if (a->philosofer[i].eat_count >= a->philosofer[i].arg->must_eat
		&& a->args->must_eat != 0)
		j += 1;
	return (j);
}

int	chacker_assistant(t_all_data *a)
{
	int	i;
	int	counter;

	while (1)
	{
		i = 0;
		counter = 0;
		while (i < a->args->number_philo)
		{
			counter = checker(a, i, counter);
			if (counter == -1)
				return (0);
			i++;
		}
		if (counter == a->args->number_philo && a->args->must_eat != 0)
		{
			pthread_mutex_lock(&a->print);
			usleep(100);
			printf("sumulation end\n");
			return (0);
		}
	}
}
