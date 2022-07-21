/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:11:20 by mel-hous          #+#    #+#             */
/*   Updated: 2022/07/21 10:42:49 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void creat_philos(all_data *a)
{
    int i;
    
    i = 0;
    a->philosofer = (philo_data *)malloc(sizeof(philo_data) * a->args->number_philo);
    while(i < a->args->number_philo)
    {
        a->philosofer[i].index = i + 1;
        if (i < a->args->number_philo - 1)
            a->philosofer[i].next_philo = &a->philosofer[i + 1];
        i++;
    }
    a->philosofer[i - 1].next_philo =  &a->philosofer[0];
}

void treads_cr(all_data *a)
{
    int i;

    i = 0;
    while(i < a->args->number_philo)
    {
        pthread_mutex_init(&a->philosofer[i].fork, NULL);
    }
}