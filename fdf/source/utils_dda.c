/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:29:49 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/30 09:55:28 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (n * -1);
}

void	ft_amplify(float *X1, float *Y1, t_vars *vars)
{
	vars->x0 *= vars->amplify;
	*X1 *= vars->amplify;
	vars->y0 *= vars->amplify;
	*Y1 *= vars->amplify;
	vars->z *= vars->amplify;
	vars->z1 *= vars->amplify;
}

int	ft_get_steps(float dx, float dy)
{
	int	steps;

	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	return (steps);
}

void	ft_move_point(float *X1, float *Y1, t_vars *vars)
{
	vars->x0 += vars->start_x;
	*X1 += vars->start_x;
	*Y1 += vars->start_y;
	vars->y0 += vars->start_y;
}
