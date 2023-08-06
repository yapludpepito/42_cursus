/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:50:04 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/20 10:40:50 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death(size_t save_time, t_philo *philo)
{
	if (ft_check_death(philo))
		return (1);
	if (get_time() - save_time > philo->time_last_eat + \
		philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->display);
		printf("\033[34;01m\n%ldms, %d died\033[00m", \
			get_time() - save_time, philo->id);
		pthread_mutex_unlock(&philo->data->display);
		pthread_mutex_lock(&philo->data->die);
		philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->data->die);
		return (1);
	}
	return (0);
}

int	ft_check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->die);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->die);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->die);
	return (0);
}

void	ft_display_eat(t_philo *philo, size_t save_time)
{
	pthread_mutex_lock(&philo->data->display);
	printf("\n%ldms, %d is eating", get_time() - save_time, philo->id);
	pthread_mutex_unlock(&philo->data->display);
}

int	ft_eat_for_last(t_philo *philo, size_t save_time)
{
	size_t	time_start;

	if (ft_check_death(philo))
		return (1);
	ft_display_eat(philo, save_time);
	if (ft_death(save_time, philo))
		return (1);
	philo->time_last_eat = get_time() - save_time;
	philo->nb_eat++;
	time_start = get_time();
	while (get_time() - time_start < (size_t)philo->data->time_to_eat)
	{
		usleep(500);
		if (ft_death(save_time, philo))
			return (1);
	}
	pthread_mutex_lock(&(philo->data->philo[0].fork));
	philo->data->philo[0].l_fork = 1;
	pthread_mutex_unlock(&(philo->data->philo[0].fork));
	pthread_mutex_lock(&philo->fork);
	philo->need_eat = 1;
	philo->l_fork = 1;
	pthread_mutex_unlock(&(philo->fork));
	return (0);
}

int	ft_eat(t_philo *philo, size_t save_time)
{
	size_t	time_start;

	if (ft_check_death(philo))
		return (1);
	ft_display_eat(philo, save_time);
	if (ft_death(save_time, philo))
		return (1);
	philo->time_last_eat = get_time() - save_time;
	philo->nb_eat++;
	time_start = get_time();
	while (get_time() - time_start < (size_t)philo->data->time_to_eat)
	{
		usleep(500);
		if (ft_death(save_time, philo))
			return (1);
	}
	pthread_mutex_lock(&(philo->data->philo[philo->id].fork));
	philo->data->philo[philo->id].l_fork = 1;
	pthread_mutex_unlock(&(philo->data->philo[philo->id].fork));
	pthread_mutex_lock(&philo->fork);
	philo->need_eat = 1;
	philo->l_fork = 1;
	pthread_mutex_unlock(&(philo->fork));
	return (0);
}
