/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:37:22 by mel-hous          #+#    #+#             */
/*   Updated: 2022/07/28 15:18:14 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(char *str, t_philo_data *a)
{
	if (a->all_info->philo_dead == 0)
	{
		pthread_mutex_lock(&a->all_info->lock_print);
		printf("%u %d %s\n", actuel_time() - a->all_info->starting_time,
			a->index, str);
		pthread_mutex_unlock(&a->all_info->lock_print);
	}
}

unsigned int	actuel_time(void)
{
	struct timeval	time;
	unsigned int	res;

	gettimeofday(&time, NULL);
	res = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (res);
}
