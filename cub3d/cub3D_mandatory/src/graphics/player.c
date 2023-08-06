/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:59:01 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/02/17 14:59:02 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

t_player	*init_player(t_game *game)
{
	t_player	*player;
	t_vec		pos;

	player = ft_calloc(1, sizeof(t_player));
	player->position = ft_calloc(1, sizeof(t_vec));
	player->walk_dir = ft_calloc(1, sizeof(t_vec));
	player->turn_dir = ft_calloc(1, sizeof(t_vec));
	player->rays = init_rays(NB_RAYS);
	player->dir = get_player_pos(game->map->map, &pos);
	player->position->x = (MAP_TILE * (pos.x)) + MAP_TILE / 2;
	player->position->y = (MAP_TILE * (pos.y)) + MAP_TILE / 2;
	player->walk_dir->x = 0;
	player->walk_dir->y = 0;
	player->turn_dir->x = 0;
	player->turn_dir->y = 0;
	player->rot_angle = set_player_dir(player->dir);
	player->walk_speed = 100.0;
	player->turn_speed = 90.0 * (PI / 180.0);
	return (player);
}

float	set_player_dir(char dir)
{
	if (dir == 'N')
		return (-90.0 * (PI / 180.0));
	else if (dir == 'S')
		return (90.0 * (PI / 180.0));
	else if (dir == 'E')
		return ((PI / 180.0));
	else if (dir == 'W')
		return (-180.0 * (PI / 180.0));
	return (0);
}

char	get_player_pos(char **map, t_vec *pos)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
			{
				pos->x = j;
				pos->y = i;
				return (map[i][j]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	render_minimap_player(t_game *game)
{
	t_vec	end_line;
	t_vec	pos_offset;

	pos_offset = *(game->player->position);
	pos_offset.x -= (5 / 2);
	pos_offset.y -= (5 / 2);
	end_line.x = (game->player->position->x) \
		+ cos(game->player->rot_angle) * (40);
	end_line.y = (game->player->position->y) \
		+ sin(game->player->rot_angle) * (40);
	draw_line(game, game->player->position, &end_line, 0);
	draw_rect(game, pos_offset, (t_vec){5, 5}, rgba2int(10, 230, 12, 255));
}
