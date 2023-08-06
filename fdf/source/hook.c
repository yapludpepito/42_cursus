/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:18:57 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/30 09:55:30 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void)y;
	(void)x;
	if (button == 4)
		vars->amplify += 1;
	if (button == 5)
	{
		vars->amplify -= 1;
		if (vars->amplify < 0)
			vars->amplify = 0.5;
	}
	ft_reload_display(vars);
	return (0);
}

void	key_hook_next(int keycode, t_vars *vars)
{
	if (keycode == 65288)
	{
		vars->angle = 0.79;
		vars->elevation = 0.05;
		vars->amplify = 20;
		vars->start_x = 300;
		vars->start_y = 100;
	}
	else if (keycode == 102)
	{
		if (vars->angle != PI)
			vars->angle = PI;
		else
			vars->angle = 0.79;
	}
	ft_reload_display(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_destroy_window(vars);
	else if (keycode == 61)
		vars->elevation += 0.005;
	else if (keycode == 45)
		vars->elevation -= 0.005;
	else if (keycode == 65363)
		vars->start_x -= 20;
	else if (keycode == 65364)
		vars->start_y -= 20;
	else if (keycode == 65361)
		vars->start_x += 20;
	else if (keycode == 65362)
		vars->start_y += 20;
	else if (keycode == 114)
		vars->angle += 0.05;
	else
		key_hook_next(keycode, vars);
	ft_reload_display(vars);
	return (0);
}
