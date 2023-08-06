/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:03:54 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/02/17 15:03:55 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_check_texture(char *line, int i, t_game *game)
{
	if (line[i] == 'N')
		ft_check_n(line, game);
	else if (line[i] == 'S')
		ft_check_s(line, game);
	else if (line[i] == 'W')
		ft_check_w(line, game);
	else if (line[i] == 'E')
		ft_check_e(line, game);
}

void	ft_check_rgb(char *line, int i, t_game *game)
{
	if (line[i] == 'F')
	{
		if (game->map->floor->r != -1)
		{
			free(line);
			ft_error(6, game);
		}
		ft_check_f(line, game);
		ft_get_rgb(line, game->map->floor, game);
	}
	else if (line[i] == 'C')
	{
		if (game->map->cell->r != -1)
		{
			free(line);
			ft_error(6, game);
		}
		ft_check_c(line, game);
		ft_get_rgb(line, game->map->cell, game);
	}
}

void	ft_count_line(char **line, int fd, int *i, t_game *game)
{
	int	j;

	j = 0;
	while ((*line))
	{
		(*i) = 0;
		ft_skip_whitespace((*line), i);
		if ((*line)[(*i)] == '0' || (*line)[(*i)] == '1')
			break ;
		free((*line));
		(*line) = get_next_line(fd);
	}
	(*i) = 1;
	while ((*line))
	{
		j = 0;
		ft_skip_whitespace((*line), &j);
		if (((*line)[j]) == '\n' || ((*line)[j]) == '\0')
			break ;
		(*i)++;
		free((*line));
		(*line) = get_next_line(fd);
	}
	check_double_map(line, game, fd);
}

char	**ft_parse_next(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	ft_count_line(&line, fd, &i, game);
	if (line)
		free(line);
	close(fd);
	map = ft_calloc(sizeof(char *), (i + 2));
	ft_get_map(filename, map);
	return (map);
}

char	**parse(int argc, char **argv, t_game *game)
{
	int		i;
	char	**map;

	i = 0;
	if (argc != 2)
		ft_error(0, game);
	while (argv[1][i])
		i++;
	if (i < 4)
		ft_error(1, game);
	if (argv[1][i - 4] != '.' || argv[1][i - 3] != 'c' \
		|| argv[1][i - 2] != 'u' || argv[1][i - 1] != 'b')
		ft_error(1, game);
	ft_get_info_map(argv[1], game);
	free(game->map->map);
	game->map->map = NULL;
	map = ft_parse_next(argv[1], game);
	return (map);
}
