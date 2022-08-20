/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:34:53 by mel-hous          #+#    #+#             */
/*   Updated: 2022/08/20 09:52:30 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	main(int ac, char **av)
{
	t_all_data	*philo;

	if (ac > 6 || ac < 5)
		return (write(2, "invalid number of args\n", 24), 1);
	philo = (t_all_data *)malloc(sizeof(t_all_data));
	philo->args = iniit();
	if (pars(av) != 0)
		return (1);
	if (args_conv(av, philo->args) == -1)
		return (write(2, "YOU HAVE CROSSED THE INT LIMITS\n", 33), 1);
	if (creat_forks(philo) == -1)
		return (write(1, "MUTEX_INT ERROR\n", 17), -1);
	if (ft_run(philo) == -1)
		return (write(1, "THREAD ERROR\n", 14), -1);
	chacker_assistant(philo);
	return (0);
}
