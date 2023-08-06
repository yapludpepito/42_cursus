/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:59:50 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/02/17 17:31:21 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_error_next(int msg, t_game *game)
{
	if (msg == 4)
	{
		printf("Missing identifier\n");
		ft_free2(game);
	}
	else if (msg == 5)
	{
		printf("Invalid number(s) to make a color\n");
		ft_free2(game);
	}
	else if (msg == 5)
	{
		printf("Invalid number(s) to make a color\n");
		ft_free2(game);
	}
	else if (msg == 6)
	{
		printf("Invalid map argument\n");
		ft_free2(game);
	}
	else if (msg == 7)
	{
		printf("Invalid map\n");
		ft_free2(game);
	}
}

void	ft_error(int msg, t_game *game)
{
	printf("Error\n");
	if (msg == 0)
	{
		printf("Invalid number of arguments\n");
		ft_free(game);
	}
	else if (msg == 1)
	{
		printf("Wrong extension\n");
		ft_free(game);
	}
	else if (msg == 2)
	{
		printf("There is already a path\n");
		ft_free2(game);
	}
	else if (msg == 3)
	{
		printf("No path found\n");
		ft_free2(game);
	}
	else
		ft_error_next(msg, game);
	exit(1);
}

void	check_double_map(char **line, t_game *game, int fd)
{
	int	j;

	while ((*line))
	{
		j = 0;
		ft_skip_whitespace_newline(*line, &j);
		if ((*line)[j] != '\0')
		{
			close(fd);
			free(*line);
			ft_error(7, game);
		}
		free(*line);
		*line = get_next_line(fd);
	}
}
