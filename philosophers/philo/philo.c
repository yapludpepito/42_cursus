/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:16:47 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/17 18:17:47 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
		return (-1);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_sleep(t_philo *philo, size_t save_time)
{
	size_t	time_start;

	if (ft_death(save_time, philo))
		return ;
	pthread_mutex_lock(&philo->data->display);
	printf("\n%ldms, %d sleep", get_time() - save_time, philo->id);
	pthread_mutex_unlock(&philo->data->display);
	time_start = get_time();
	while (get_time() - time_start < (size_t)philo->data->time_to_sleep)
	{
		usleep(500);
		if (ft_death(save_time, philo))
			return ;
	}
	if (ft_death(save_time, philo))
		return ;
}

void	think(t_philo *philo, size_t save_time)
{
	if (ft_death(save_time, philo))
		return ;
	pthread_mutex_lock(&philo->data->display);
	printf("\n%ldms, %d think", \
		get_time() - save_time, philo->id);
	pthread_mutex_unlock(&philo->data->display);
	philo->need_eat = 0;
}

void	eat(t_philo *philo, size_t save_time)
{
	if (philo->id == philo->data->nb_fork)
		ft_eat_for_last(philo, save_time);
	else
		ft_eat(philo, save_time);
	pthread_mutex_lock(&philo->data->die);
	if (philo->data->is_dead == 0)
	{
		pthread_mutex_unlock(&philo->data->die);
		ft_sleep(philo, save_time);
		think(philo, save_time);
	}
	else
		pthread_mutex_unlock(&philo->data->die);
}

void	*routine(void	*tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	if (philo->id % 2 == 1)
		usleep(20000);
	while (1)
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
}
