/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdead.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:22:26 by mel-hous          #+#    #+#             */
/*   Updated: 2022/07/27 14:30:58 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int chaweche(all_data *a, int i, int *j)
{
    unsigned int time_now;

    time_now = actuel_time();
    if(time_now - a->philosofer[i].last_time_eat > (unsigned int)a->philosofer[i].arg->t_die)
    {
        pthread_mutex_lock(&a->philosofer[i].eating);
        pthread_mutex_lock(&a->philosofer[i].all_info->lock_print);
        printf("%u %d %s\n", actuel_time() - a->philosofer->all_info->starting_time,a->philosofer[i].index,"is dead");
        return(-1);
    }
    // printf("EAT =%d\n",a->philosofer[i].eat_count);
    if(a->philosofer[i].eat_count >= a->philosofer[i].arg->must_eat)
        (*j) += 1;
    return(0);
}

int inspector(all_data *a)
{
    int i;
    int min_eat_cont;

    while(1)
    {
        i = 0;
        min_eat_cont = 0;
        while(i < a->args->number_philo)
        {
            if(chaweche(a, i, &min_eat_cont) == -1)
                return(1);
            i++;
        }
        if (min_eat_cont == a->args->number_philo && a->args->must_eat != 0)
        {
            pthread_mutex_lock(&a->lock_print);
            printf("sumulation end\n");
            return(0);
        }
    }
    return(0);
}