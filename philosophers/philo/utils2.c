/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:49:59 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/21 12:54:02 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_go_eat(t_philo *philo)
{
	if (ft_death(philo->data->save_time, philo))
	{
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	philo->l_fork = 0;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_lock(&(philo->data->philo[philo->id].fork));
	if (philo->data->philo[philo->id].l_fork == 1)
	{
		philo->data->philo[philo->id].l_fork = 0;
		pthread_mutex_unlock(&(philo->data->philo[philo->id].fork));
		pthread_mutex_lock(&philo->data->display);
		printf("\n%ldms, %d take left fork", \
			get_time() - philo->data->save_time, philo->id);
		printf("\n%ldms, %d take right fork", \
			get_time() - philo->data->save_time, philo->id);
		pthread_mutex_unlock(&philo->data->display);
		eat(philo, philo->data->save_time);
	}
	else
		pthread_mutex_unlock(&(philo->data->philo[philo->id].fork));
	return (0);
}

int	ft_go_eat_last(t_philo *philo)
{
	if (ft_death(philo->data->save_time, philo))
	{
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	philo->l_fork = 0;
	pthread_mutex_unlock(&philo->fork);
	if (ft_death(philo->data->save_time, philo))
		return (1);
	pthread_mutex_lock(&(philo->data->philo[0].fork));
	if (philo->data->philo[0].l_fork == 1)
	{
		philo->data->philo[0].l_fork = 0;
		pthread_mutex_unlock(&(philo->data->philo[0].fork));
		pthread_mutex_lock(&philo->data->display);
		printf("\n%ldms, %d take left fork", \
			get_time() - philo->data->save_time, philo->id);
		printf("\n%ldms, %d take right fork", \
			get_time() - philo->data->save_time, philo->id);
		pthread_mutex_unlock(&philo->data->display);
		eat(philo, philo->data->save_time);
	}
	else
		pthread_mutex_unlock(&(philo->data->philo[0].fork));
	return (0);
}

void	*routine2(void	*tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	if (philo->id % 2 == 1)
		usleep(20000);
	while (philo->nb_eat <= philo->data->nb_eat_needed)
	{
		if (ft_death(philo->data->save_time, philo))
			return (NULL);
		pthread_mutex_lock(&philo->fork);
		if (philo->id < philo->data->nb_fork)
		{
			if (ft_go_eat(philo))
				return (NULL);
		}
		else
		{
			if (ft_go_eat_last(philo))
				return (NULL);
		}
		if (ft_check_death(philo))
			return (NULL);
	}
	return (NULL);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	long long int	value;

	i = 0;
	sign = 1;
	value = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = value * 10 + (nptr[i] - 48);
		i++;
	}
	return ((int)(value * sign));
}

long long int	ft_atoll(const char *nptr)
{
	long long		i;
	long long		sign;
	long long int	value;

	i = 0;
	sign = 1;
	value = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = value * 10 + (nptr[i] - 48);
		i++;
	}
	return ((value * sign));
}
