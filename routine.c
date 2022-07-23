/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:31:32 by mel-hous          #+#    #+#             */
/*   Updated: 2022/07/23 11:20:53 by mel-hous         ###   ########.fr       */
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

unsigned int actuel_time(void)
{
    struct timeval time;
    unsigned int res;
    
    gettimeofday(&time, NULL);
    res = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return(res);
}

void eating_time(philo_data *a)
{
    pthread_mutex_lock(&a->eating);
    printf("");
    a->last_time_eat = actuel_time();
    sleep(a->arg->t_eat / 1000);
    a->eat_count += 1;
    pthread_mutex_unlock(&a->eating);
    pthread_mutex_unlock(&a->fork);
    pthread_mutex_unlock(&a->next_philo->fork);
}

void sleeping_time(philo_data *a)
{
    printf("");
    usleep(a->arg->t_sleep * 1000);
}

void *theory(void *arg)
{
    philo_data *a;

    a = (philo_data *)arg
    while(1)
    {
        lock_forks(a);
        eating_time(a);
        
    }
}