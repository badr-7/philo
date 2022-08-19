/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:34:53 by mel-hous          #+#    #+#             */
/*   Updated: 2022/08/19 10:56:37 by mel-hous         ###   ########.fr       */
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

void	creat_treads(t_all_data *a, int chosen_ones)
{
	int	i;

	i = chosen_ones;
	while (i < a->args->number_philo)
	{
		a->philosofer[i].all_info = a;
		a->philosofer[i].eat_count = 0;
		a->philosofer[i].last_time_eat = actuel_time();
		if (pthread_create(&a->philosofer[i].philo, NULL, theory,
				(void *)&a->philosofer[i]) != 0)
			return (-1);
		if (pthread_detach(a->philosofer[i].philo) != 0)
			return (-1);
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
		return (write(2, "invalid number of args\n", 24), 1);
	philo = (t_all_data *)malloc(sizeof(t_all_data));
	a = iniit();
	philo->args = a;
	if (pars(av) != 0)
		return (1);
	if (args_conv(av, a) == -1)
		return (write(2, "YOU HAVE CROSSED THE INT LIMITS\n", 33), 1);
	if (creat_forks(philo) == -1)
		return (write(1, "MUTEX_INT ERROR", 1), -1);
	ft_run(philo);
	lmkadem(philo);
	return (0);
}
