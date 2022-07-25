/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:11:20 by mel-hous          #+#    #+#             */
/*   Updated: 2022/07/25 16:02:45 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void creat_forks(all_data *a, t_args *b)
{
    int i;
    
    i = 0;
    a->philosofer = (philo_data *)malloc(sizeof(philo_data) * a->args->number_philo);
    while(i < a->args->number_philo)
    {
        a->philosofer[i].arg = b;
        a->philosofer[i].index = i + 1;
        pthread_mutex_init(&a->philosofer[i].fork, NULL);
        pthread_mutex_init(&a->philosofer[i].eating, NULL);
        if (i < a->args->number_philo - 1)
            a->philosofer[i].next_philo = &a->philosofer[i + 1];
        i++;
    }
    a->philosofer[i - 1].next_philo =  &a->philosofer[0];
    a->starting_time = actuel_time();
}
