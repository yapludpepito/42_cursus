/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:32:12 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/02/17 17:31:30 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <float.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

// ----------------------- DEFINES ------------------------- //
# define TRUE 1
# define FALSE 0
# define PI 3.14159265
# define TWO_PI 6.28318530
# define WIN_WIDTH 1600
# define WIN_HALF_W 800
# define WIN_HEIGHT 900
# define WIN_HALF_H 450
# define MAP_TILE 64
# define FOV_ANGLE 1.04719755
# define HALF_FOV 0.523598775
# define NB_RAYS 1600
# define DELTA_ANGLE 0.000654498
# define SCREEN_DIST 1385.64064797

// ----------------------- STRUCTS ------------------------- //
typedef struct s_game		t_game;
typedef struct s_ray		t_ray;
typedef struct s_interc		t_interc;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_vec		t_vec;
typedef struct s_rect		t_rect;
typedef struct s_texture	t_texture;
typedef struct s_wall		t_wall;
typedef struct s_color		t_color;

typedef struct s_texture
{
	mlx_texture_t	*tex_img;
	char			*path;
}	t_texture;

typedef struct s_wall
{
	t_texture	*n;
	t_texture	*s;
	t_texture	*e;
	t_texture	*w;
}	t_wall;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_vec
{
	float	x;
	float	y;
}	t_vec;

typedef struct s_rect
{
	t_vec	position;
	t_vec	size;
	t_color	color;
}	t_rect;

typedef struct s_ray
{
	float		ray_angle;
	float		wallhit_x;
	float		wallhit_y;
	float		distance;
	int			was_hit_vertical;
	int			hit_content;
	int			ray_face_up;
	int			ray_face_down;
	int			ray_face_left;
	int			ray_face_right;
}	t_ray;

typedef struct s_interc
{
	int			found_wall_hit;
	int			wall_content;
	int			is_ray_fac_down;
	int			is_ray_fac_up;
	int			is_ray_fac_right;
	int			is_ray_fac_left;
	float		hit_distance;
	float		wall_hit_x;
	float		wall_hit_y;
	t_vec		*next_touch;
	t_vec		*to_check;
	t_vec		*interc;
	t_vec		*step;
}	t_interc;

typedef struct s_map
{
	t_wall		*wall_texture;
	t_color		*floor;
	t_color		*cell;
	int			height;
	int			width;
	char		**map;
}	t_map;

typedef struct s_player
{
	t_vec	*position;
	t_vec	*walk_dir;
	t_vec	*turn_dir;
	t_ray	*rays;
	char	dir;
	float	fov_angle;
	float	rot_angle;
	float	walk_speed;
	float	turn_speed;
}	t_player;

typedef struct s_game
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*mlx_img;
	mlx_image_t	*minimap;
	t_player	*player;
	t_interc	interct;
	t_interc	ray_inter_v;
	t_interc	ray_inter_h;
	double		last_time;
	double		current_time;
}	t_game;

// -------------------------- INITS ------------------------- //
t_game			*init_game(int ac, char **av);
t_map			*init_map(void);
t_player		*init_player(t_game *game);
t_ray			*init_rays(int nb_rays);
float			set_player_dir(char dir);
char			get_player_pos(char **map, t_vec *pos);

// ------------------------- RENDERS ------------------------ //
void			render_minimap_player(t_game *game);
void			render_3d(t_game *game);
void			draw_walls(t_game *game, int pos_xy[2], \
					t_vec wall_pixels);
mlx_texture_t	*get_wall_texture(t_game *game, t_ray *ray);
int				get_wall_texture_y(t_vec wall_pixels, int pos_y, \
					mlx_texture_t *texture);
int				get_wall_texture_x(t_ray *ray, mlx_texture_t *texture);
t_vec			get_wall_position_pixels(float h_proj_wall);
void			draw_vertical_strip(t_game *game, int pos_xy[2], \
					t_vec wall_pixels);
uint32_t		get_pixel(mlx_texture_t *texture, uint32_t x, uint32_t y);
void			put_pixel(mlx_image_t *image, uint32_t x, uint32_t y, \
					uint32_t color);
void			draw_line(t_game *game, t_vec *start, t_vec *end, int color);
void			draw_rect(t_game *game, t_vec pos, t_vec size, int color);
int32_t			average_color(int start_color, int end_color, float f);

// ------------------------ GAMELGCS ----------------------- //
void			game_routine(void *param);
void			input_handler(t_game *game);
void			move_player(t_game *game);
void			render(t_game *game);

// ------------------------ RAYS ----------------------- //
void			cast_all_rays(t_game *game);
void			cast_ray(t_game *game, float ray_angle, int ray_id);
int				is_in_map(t_game *game, t_vec pos);
int				get_collision(t_game *game, t_vec pos);
float			normalize_angle(float *angle);
float			distance_ab(t_vec a, t_vec b);
int				rgba2int(int r, int g, int b, int a);
void			horizontal_wall_hits(t_game *game);
void			horizontal_interc(t_game *game, float ray_angle);
void			vertical_wall_hits(t_game *game);
void			vertical_interc(t_game *game, float ray_angle);
void			reset_ray(t_interc *hv);
void			put_on_rays_struct(t_interc hv, t_game *game, \
					int was_hit_v, int ray_id);
void			take_smallest_r_infos(t_game *game, \
					float ray_angle, int ray_id);

// ------------------------- PARSING ------------------------ //
int				get_height(char **map);
int				get_width(char **map);
char			**parse(int argc, char **argv, t_game *game);
char			**ft_verif_map(char **map);
void			check_player_pos(t_game *game);
void			ft_skip_whitespace(char *line, int *i);
void			ft_skip_whitespace_newline(char *line, int *i);
void			ft_skip_number(char *line, int *i);
void			fill_first_line(char **map, char **new_map);
void			fill_first_space_line(char **map, char **new_map);
void			fill_last_line(char **map, char **new_map);
void			fill_last_space_line(char **map, char **new_map);
void			fill_line_border(char **map, char **new_map);
int				ft_map_length(char **map);
int				ft_find_big_line(char **map);
void			ft_check_n(char *line, t_game *game);
void			ft_check_s(char *line, t_game *game);
void			ft_check_w(char *line, t_game *game);
void			ft_check_e(char *line, t_game *game);
void			ft_check_empty_args(t_game *game);
void			ft_check_f_next(char **check, t_game *game, char *line);
void			ft_check_f(char *line, t_game *game);
void			ft_check_c_next(char **check, t_game *game, char *line);
void			ft_check_c(char *line, t_game *game);
void			ft_get_rgb(char *line, t_color *color, t_game *game);
void			ft_get_info_map(char *file, t_game *game);
void			ft_get_map(char *filename, char **map, t_game *game);
void			ft_check_texture(char *line, int i, t_game *game);
void			ft_check_rgb(char *line, int i, t_game *game);
void			ft_error(int msg, t_game *game);
void			ft_free(t_game *game);
void			ft_free2(t_game *game);
void			ft_free3(t_game *game);
void			ft_free_split(char **strs);
void			check_double_map(char **line, t_game *game, int fd);

#endif
