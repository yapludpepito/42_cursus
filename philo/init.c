/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:50:12 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/19 16:50:12 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	init_philo(t_data *data)
{
	static int	j = 0;
	t_philo		philo;

	++j;
	philo.id = j;
	philo.l_fork = 1;
	philo.nb_eat = 0;
	philo.need_eat = 0;
	philo.time_last_eat = 0;
	philo.data = data;
	pthread_mutex_init(&philo.fork, NULL);
	return (philo);
}

t_data	*init_data(char **argv)
{
	t_data	*data;
	int		i;

	i = 0;
	data = malloc(sizeof(t_data) * 1);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->nb_fork = ft_atoi(argv[1]);
	data->is_dead = 0;
	if (argv[5])
		data->nb_eat_needed = ft_atoi(argv[5]);
	data->save_time = get_time();
	pthread_mutex_init(&data->display, NULL);
	pthread_mutex_init(&data->die, NULL);
	data->philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (data->philo == NULL)
		exit (0);
	while (i < ft_atoi(argv[1]))
	{
		data->philo[i] = init_philo(data);
		i++;
	}
	return (data);
}
