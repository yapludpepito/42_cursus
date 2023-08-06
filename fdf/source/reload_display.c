/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:58:50 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/30 09:55:29 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_reload_display(t_vars *vars)
{
	ft_color_all(vars);
	vars->y = 0;
	while (vars->y < vars->len)
	{
		vars->x = 0;
		while (vars->x < vars->width)
		{
			if (vars->x < vars->width - 1)
				ft_dda((vars->x) + 1, (vars->y), vars);
			if (vars->y < vars->len - 1)
				ft_dda((vars->x), (vars->y) + 1, vars);
			(vars->x)++;
		}
		(vars->y)++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
