/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:49:49 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/21 13:00:51 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo(int i, char **argv, t_data *data)
{
	while (++i < ft_atoi(argv[1]))
		pthread_create(&data->philo[i].tid, NULL, \
			&routine, &data->philo[i]);
	i = -1;
	while (++i < ft_atoi(argv[1]))
		pthread_join(data->philo[i].tid, NULL);
}

int	ft_parsing_next(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoll(argv[i]) > 2147483647)
		{
			printf("Error : overflow\n");
			return (-1);
		}
		if (ft_atoll(argv[i]) < -2147483648)
		{
			printf("Error : underflow\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_parsing(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("invalid number of arg : %d\n", argc - 1);
		return (1);
	}
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 60 && i != 1 && i != 5)
		{
			printf("invalid arg : %s\n", argv[i]);
			return (1);
		}
		i++;
	}
	if (ft_parsing_next(argv) == -1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	if (ft_parsing(argc, argv) == 1)
		return (1);
	data = init_data(argv);
	i = -1;
	data->save_time = get_time();
	if (argc == 5)
		ft_philo(i, argv, data);
	else
	{
		while (++i < ft_atoi(argv[1]))
			pthread_create(&data->philo[i].tid, NULL, \
				&routine2, &data->philo[i]);
		i = -1;
		while (++i < ft_atoi(argv[1]))
			pthread_join(data->philo[i].tid, NULL);
	}
	printf("\n\n");
	free(data->philo);
	free(data);
	return (0);
}
