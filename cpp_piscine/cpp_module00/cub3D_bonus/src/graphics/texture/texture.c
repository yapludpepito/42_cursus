/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:32:01 by jlarrieu          #+#    #+#             */
/*   Updated: 2023/02/17 12:56:26 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

mlx_texture_t	*get_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->hit_content == '2')
		return (game->map->wall_texture->door->tex_img);
	if (!ray->was_hit_vertical)
	{
		if (ray->ray_face_up)
			return (game->map->wall_texture->n->tex_img);
		else
			return (game->map->wall_texture->s->tex_img);
	}
	else
	{
		if (ray->ray_face_right)
			return (game->map->wall_texture->e->tex_img);
		else
			return (game->map->wall_texture->w->tex_img);
	}
}

int	get_wall_texture_y(t_vec wall_pixels, int pos_y, mlx_texture_t *texture)
{
	return ((wall_pixels.x - pos_y) / (wall_pixels.x - wall_pixels.y) \
									* texture->height);
}

int	get_wall_texture_x(t_ray *ray, mlx_texture_t *texture)
{
	if (!ray->was_hit_vertical)
	{
		if (ray->ray_face_up)
			return ((int)(ray->wallhit_x / MAP_TILE * texture->width) \
											% texture->width);
		else
			return ((texture->width - 1) - \
					(int)(ray->wallhit_x / MAP_TILE * texture->width) \
													% texture->width);
	}
	else
	{
		if (ray->ray_face_right)
			return ((int)(ray->wallhit_y / MAP_TILE * texture->width) \
											% texture->width);
		else
			return ((texture->width - 1) - \
					(int)(ray->wallhit_y / MAP_TILE * texture->width) \
													% texture->width);
	}
}
