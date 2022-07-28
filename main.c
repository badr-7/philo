/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:34:53 by mel-hous          #+#    #+#             */
/*   Updated: 2022/07/28 14:42:24 by mel-hous         ###   ########.fr       */
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

t_philo_data	*iniit2(void)
{
	t_philo_data	*a;

	a = (t_philo_data *)malloc(sizeof(t_philo_data));
	a->index = 0;
	a->next_philo = NULL;
	a->last_time_eat = 0;
	pthread_mutex_init(&a->fork, NULL);
	return (a);
}

void	creat_treads(t_all_data *a, int chosen_ones)
{
	int	i;

	i = chosen_ones;
	while (i < a->args->number_philo)
	{
		a->philosofer[i].all_info = a;
		a->philosofer[i].eat_count = 0;
		a->philosofer[i].last_time_eat = actuel_time();
		pthread_create(&a->philosofer[i].philo, NULL, theory,
			(void *)&a->philosofer[i]);
		pthread_detach(a->philosofer[i].philo);
		i += 2;
	}	
}

void	ft_run(t_all_data *a)
{
	creat_treads(a, 0);
	usleep(100);
	creat_treads(a, 1);
}

int	main(int ac, char **av)
{
	t_args		*a;
	t_all_data	*philo;

	if (ac > 6 || ac < 5)
		exit (write(2, "invalide number of args\n", 25));
	philo = (t_all_data *)malloc(sizeof(t_all_data));
	a = iniit();
	philo->args = a;
	philo->philo_dead = 0;
	if (pars(av) != 0)
		return (1);
	args_conv(av, a);
	creat_forks(philo, a);
	ft_run(philo);
	lmkadem(philo);
	return (0);
}
