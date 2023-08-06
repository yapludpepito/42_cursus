/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:24:19 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/29 13:57:00 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef PI
#  define PI 3.14159
# endif

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	t_data	img;
	void	*mlx;
	void	*win;
	int		**maps;
	int		len;
	int		width;
	float	x;
	float	y;
	float	x0;
	float	y0;
	float	elevation;
	double	z;
	double	z1;
	int		amplify;
	int		start_x;
	int		start_y;
	int		color;
	int		r;
	int		g;
	int		b;
	double	angle;
	int		fd;
}				t_vars;

/*----------------------------------------------------------------------------*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/*----------------------------------------------------------------------------*/

char	**ft_split(char const *s, char c);

/*----------------------------------------------------------------------------*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_dda(float X1, float Y1, t_vars *vars);
void	ft_put_pixel(int x, int y, int color, t_vars *vars);
void	ft_isometric(float *x, float *y, double z, double angle);
void	ft_amplify(float *X1, float *Y1, t_vars *vars);
void	ft_move_point(float *X1, float *Y1, t_vars *vars);
void	ft_reload_display(t_vars *vars);
void	display(t_vars *vars);
void	ft_color_all(t_vars *vars);
void	ft_reload_display_boule(t_vars *vars);
void	ft_sphere(float X1, float Y1, t_vars *vars);
void	ft_free_maps(t_vars *vars, int **maps, char **line_split);
void	ft_check_maps(t_vars *vars, int **maps, char **line_split, char *line);
void	ft_exit(void);

/*----------------------------------------------------------------------------*/

int		ft_get_width(int fd);
int		ft_get_height(int fd);
int		ft_atoi(const char *nptr);
int		ft_count_num(char **maps);
int		abs(int n);
int		ft_get_steps(float dx, float dy);
int		ft_convert_hexa(char **maps, int *n, int *j, int *i);
int		ft_destroy_window(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		create_rgb(int r, int g, int b);
int		**ft_get_int_map(int **map, char **maps);

/*----------------------------------------------------------------------------*/

#endif
