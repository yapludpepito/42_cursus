/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:03:33 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/02/17 15:03:33 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	check_player_pos(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] != ' ' \
				&& game->map->map[i][j] != '1' \
					&& game->map->map[i][j] != '0' \
						&& game->map->map[i][j] != '2')
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return ;
	ft_free_split(game->map->map);
	ft_error(7, game);
}
