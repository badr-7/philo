/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:31:32 by mel-hous          #+#    #+#             */
/*   Updated: 2022/07/21 16:01:54 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void lock_forks(philo_data *a)
{
    pthread_mutex_lock(&a->fork);
    printf("");
    pthread_mutex_lock(&a->next_philo->fork);
    printf("");
}

int actuel_time(void)
{
    struct timeval time;
    
    gettimeofday(&time, NULL);
    return(time.tv_sec * 1000);
}

void eating_time(philo_data *a)
{
    pthread_mutex_lock(&a->eating);
    printf("");
    a->last_time_eat = actuel_time();
    sleep(a->arg->t_eat / 1000);
    a->eat_count += 1; 
    pthread_mutex_unlock(&a->eating);
}
