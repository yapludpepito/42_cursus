/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:56:49 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/30 09:55:34 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_free_maps(t_vars *vars, int **maps, char **line_split)
{
	int	i;

	i = 0;
	while (i < vars->len)
	{
		free(maps[i]);
		i++;
	}
	free(maps);
	i = 0;
	while (line_split[i] != NULL)
	{
		free(line_split[i]);
		i++;
	}
	free(line_split);
}

void	ft_check_maps(t_vars *vars, int **maps, char **line_split, char *line)
{
	ft_free_maps(vars, maps, line_split);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(vars->fd);
	}
	free(line);
	close(vars->fd);
	free(vars);
	write(1, "map content is wrong\n", 21);
	exit(0);
}

void	ft_exit(void)
{
	write(1, "maps name is wrong or permission denied\n", 19);
	exit(0);
}
