/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:00:16 by mel-hous          #+#    #+#             */
/*   Updated: 2022/08/16 09:47:18 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	is_digit(char c)
{
	if (c >= '0' || c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char	*str)
{
	int			i;
	long int	result;

	result = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		if (result > 2147483647)
			return (-1);
		else if (result < -2147483648)
			return (-1);
		i++;
	}
	return (result);
}

int	pars(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = 0;
		if (s[i][j] == '\0')
			return (write(2, "EMPTY ARGUMENT\n", 16), 1);
		while (s[i][j])
		{
			if ((s[i][j] >= 58 && s[i][j] <= 127)
			|| (s[i][j] >= 33 && s[i][j] <= 47))
			{
				write(2, "INVALID TYPE OF ARGUMENT\n", 26);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	args_conv(char **s, t_args *a)
{
	a->number_philo = ft_atoi(s[1]);
	a->t_die = ft_atoi(s[2]);
	a->t_eat = ft_atoi(s[3]);
	a->t_sleep = ft_atoi(s[4]);
	if (s[5])
	{
		a->must_eat = ft_atoi(s[5]);
		if (a->must_eat == -1)
			return (-1);
	}
	if (a->number_philo == -1 || a->t_die == -1
		|| a->t_eat == -1 || a->t_sleep == -1)
		return (-1);
	return (0);
}
