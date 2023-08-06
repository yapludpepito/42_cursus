/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:15:30 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/30 09:55:36 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y > 0 && y <= 1080 && x > 0 && x <= 1920)
	{
		dst = data->addr;
		dst += (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	ft_destroy_window(t_vars *vars)
{
	int	i;

	i = 0;
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	while (i < vars->len)
	{
		free(vars->maps[i]);
		i++;
	}
	free(vars->maps);
	free(vars->mlx);
	free(vars);
	exit(0);
}

void	ft_put_pixel(int x, int y, int color, t_vars *vars)
{
	my_mlx_pixel_put(&vars->img, x, y, color);
}

void	display(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "fil de fer");
	vars->img.img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	ft_color_all(vars);
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
	mlx_hook(vars->win, 2, 1L, &key_hook, vars);
	mlx_hook(vars->win, 4, (1L << 2), &mouse_hook, vars);
	mlx_hook(vars->win, 17, (1L << 17), ft_destroy_window, vars);
	mlx_loop(vars->mlx);
}
