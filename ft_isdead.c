/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdead.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:22:26 by mel-hous          #+#    #+#             */
/*   Updated: 2022/08/19 16:00:15 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	chaweche(t_all_data *a, int i, int j)
{
	if (actuel_time() - a->philosofer[i].last_time_eat
		>= (unsigned int)a->philosofer[i].arg->t_die)
	{
		if (a->philosofer[i].is_eating == 0)
			return (0);
		pthread_mutex_lock(&a->print);
		usleep(100);
		printf("%u %d %s\n", actuel_time() - a->starting_time,
			a->philosofer[i].index, "is dead");
		return (-1);
	}
	if (a->philosofer[i].eat_count >= a->philosofer[i].arg->must_eat
		&& a->args->must_eat != 0)
		j += 1;
	return (j);
}

int	lmkadem(t_all_data *a)
{
	int	i;
	int	counter;

	while (1)
	{
		i = 0;
		counter = 0;
		while (i < a->args->number_philo)
		{
			counter = chaweche(a, i, counter);
			if (counter == -1)
				return (-1);
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
