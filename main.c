/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:34:53 by mel-hous          #+#    #+#             */
/*   Updated: 2022/07/23 10:48:58 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

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
philo_data	*iniit2(void)
{
	philo_data	*a;

	a = (philo_data *)malloc(sizeof(philo_data));
	a->index = 0;
	a->next_philo = NULL;
	a->last_time_eat = 0;
	pthread_mutex_init(&a->fork, NULL);
	return (a);
}
void creat_treads(all_data *a, int chosen_ones)
{
	int i;

	i = chosen_ones;
	while(i < a->args->number_philo)
	{
		a->philosofer[i].all_info = a;
		pthread_create(&a->philosofer[i].philo, NULL, lock_forks(), a);
	}
	
}
int main(int ac, char **av)
{
	t_args *a;
	all_data *philo;
	
	if(ac > 6 || ac < 5)
		exit (write(2, "invalide number of args\n", 25));
	philo = (all_data *)malloc(sizeof(all_data));
    a = iniit();
	philo->args = a;
	pars(av);
	args_conv(av, a);
	creat_forks(philo, a);
	return (0);
}
