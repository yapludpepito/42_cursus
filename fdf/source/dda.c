/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:49:27 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/30 09:55:35 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	create_rgb(int r, int g, int b)
{
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return (r << 16 | g << 8 | b);
}

void	ft_dda_next(t_vars *vars, float X1, float Y1)
{
	float	dx;
	float	dy;
	float	steps;

	dy = Y1 - vars->y0;
	dx = X1 - vars->x0;
	steps = ft_get_steps(dx, dy);
	dx /= steps;
	dy /= steps;
	while (((int)(vars->x0 - X1) || (int)(vars->y0 - Y1)))
	{
		vars->r = (vars->z > 5) * (vars->z * 2);
		vars->g = ((vars->z > 5) * 150 + (vars->z * 2));
		vars->b = (vars->z > 5) * (vars->z * 2)
			+ (vars->z <= 5) * (150 + (vars->z * 2));
		ft_put_pixel(vars->x0, vars->y0,
			create_rgb(vars->r, vars->g, vars->b), vars);
		vars->x0 += dx;
		vars->y0 += dy;
	}
}

void	ft_dda(float X1, float Y1, t_vars *vars)
{
	vars->y0 = vars->y;
	vars->x0 = vars->x;
	vars->z = vars->maps[(int)vars->y0][(int)vars->x0];
	vars->z1 = vars->maps[(int)Y1][(int)X1];
	if (vars->maps[(int)vars->y0][(int)vars->x0] != 0)
		vars->z *= vars->elevation * 2;
	if (vars->maps[(int)Y1][(int)X1])
		vars->z1 *= vars->elevation * 2;
	ft_amplify(&X1, &Y1, vars);
	ft_isometric(&(vars->x0), &(vars->y0), vars->z, vars->angle);
	ft_isometric(&X1, &Y1, vars->z1, vars->angle);
	ft_move_point(&X1, &Y1, vars);
	ft_dda_next(vars, X1, Y1);
}
