/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:00:16 by mel-hous          #+#    #+#             */
/*   Updated: 2022/07/26 11:03:27 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int is_digit(char c)
{
	if(c >= '0'|| c <= '9')
		return(1);
	return(0);
}

int	ft_atoi(const char	*str)
{
	int			i;
	long int	result;
	int			signe;

	result = 0;
	i = 0;
	signe = 1;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		if (result * signe > 2147483647)
			return (-1);
		else if (result * signe < -2147483648)
			return (0);
		i++;
	}
	return (result * signe);
}

int pars(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = 0;
		if(s[i][j] == '\0')
			return (write(2, "ERROR\n", 6), 1);
		while (s[i][j])
		{
			if ((s[i][j] >= 58 && s[i][j] <= 127) || (s[i][j] >= 33 && s[i][j] <= 47))
		{
			write(2, "Error\n", 6);
			return (1);
		}
			j++;
		}
		i++;
	}
	return(0);
}

void args_conv(char **s, t_args *a)
{
    if(!s)
        exit (1);
    a->number_philo = ft_atoi(s[1]);
	
    a->t_die = ft_atoi(s[2]);
    a->t_eat = ft_atoi(s[3]);
    a->t_sleep = ft_atoi(s[4]);
    if (s[5])
        a->must_eat = ft_atoi(s[5]);
}