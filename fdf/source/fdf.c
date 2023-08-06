/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:20:04 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/30 09:54:15 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	**ft_get_maps_next(char *line, char **line_split, int **maps, t_vars **vars)
{
	int	i;
	int	j;

	i = 0;
	while (line != NULL)
	{
		j = -1;
		while (line_split[++j] != NULL)
			maps[i][j] = ft_atoi(line_split[j]);
		if (j < (*vars)->width)
			ft_check_maps((*vars), maps, line_split, line);
		j = -1;
		free(line);
		while (line_split[++j] != NULL)
			free(line_split[j]);
		free(line_split);
		line = get_next_line((*vars)->fd);
		if (line != NULL)
			line_split = ft_split((const char *)line, ' ');
		i++;
	}
	return (maps);
}

int	ft_get_len(char *line, int fd)
{
	int	len;

	len = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		len++;
	}
	free(line);
	return (len);
}

int	**ft_get_maps(char *map_path, t_vars **vars)
{
	char	*line;
	int		**maps;
	char	**line_split;
	int		i;

	i = -1;
	(*vars)->fd = open(map_path, O_RDONLY);
	if ((*vars)->fd == -1)
	{
		free((*vars));
		ft_exit();
	}
	line = get_next_line((*vars)->fd);
	(*vars)->len = ft_get_len(line, (*vars)->fd);
	close((*vars)->fd);
	(*vars)->fd = open(map_path, O_RDONLY);
	line = get_next_line((*vars)->fd);
	line_split = ft_split((const char *)line, ' ');
	while (line_split[(*vars)->width] != NULL)
		(*vars)->width++;
	maps = malloc(sizeof(int *) * (*vars)->len);
	while (++i < (*vars)->len)
		maps[i] = malloc(sizeof(int) * (*vars)->width);
	maps = ft_get_maps_next(line, line_split, maps, vars);
	return (maps);
}

static void	ft_init_struct(t_vars *vars, char **argv)
{
	vars->len = 0;
	vars->width = 0;
	vars->maps = ft_get_maps(argv[1], &vars);
	vars->elevation = 0.05;
	vars->amplify = 20;
	vars->start_x = 300;
	vars->start_y = 100;
	vars->r = 150;
	vars->g = 0;
	vars->b = 0;
	vars->x = 0;
	vars->y = 0;
	vars->angle = 0.79;
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	int		i;

	i = 0;
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (argv[1][i] != '\0')
		i++;
	if (argv[1][i - 1] != 'f' || argv[1][i - 2] != 'd'
		|| argv[1][i - 3] != 'f' || argv[1][i - 4] != '.')
		ft_exit();
	vars = malloc(sizeof(t_vars) * 1);
	ft_init_struct(vars, argv);
	display(vars);
	return (0);
}
