/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:49:47 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/19 16:49:47 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				nb_eat;
	int				need_eat;
	size_t			time_last_eat;
	pthread_t		tid;
	pthread_mutex_t	fork;
	t_data			*data;
}			t_philo;

typedef struct s_data
{
	size_t			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat_needed;
	int				nb_fork;
	int				is_dead;
	size_t			save_time;
	pthread_mutex_t	display;
	pthread_mutex_t	die;
	t_philo			*philo;
}			t_data;

t_philo				init_philo(t_data *data);
t_data				*init_data(char **argv);
size_t				get_time(void);
int					ft_death(size_t save_time, t_philo *philo);
void				ft_display_eat(t_philo *philo, size_t save_time);
int					ft_check_death(t_philo *philo);
int					ft_eat(t_philo *philo, size_t save_time);
int					ft_eat_for_last(t_philo *philo, size_t save_time);
int					ft_go_eat(t_philo *philo);
void				eat(t_philo *philo, size_t save_time);
int					ft_go_eat_last(t_philo *philo);
void				*routine(void	*tmp);
void				*routine2(void	*tmp);
int					ft_atoi(const char *nptr);
long long int		ft_atoll(const char *nptr);

#endif