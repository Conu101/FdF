/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:48:00 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/05 21:36:48 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define HEIGHT			1080
# define WIDTH			1920

typedef struct s_map
{
	int					width;
	int					height;
	int					*coords_arr;
	int					*colors_arr;
	int					z_min;
	int					z_max;
	int					z_range;
	int					zoom;
}						t_map;

typedef struct s_fdf
{
	void				*mlx;
	void				*win;
	t_map				*map;
}						t_fdf;

typedef struct s_coord
{
	int					z;
	int					color;
	struct s_coord		*next;
}						t_coord;

typedef struct s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef enum s_bool
{
						false,
						true
}						t_bool;

typedef struct s_RGB
{
	int					R;
	int					G;
	int					B;
}						t_RGB;

void	terminate(char *s);
t_map	*map_init(void);
int		map_populate(const int fd, t_coord **coords_stack, t_map *map);
void	stack_to_arrays(t_coord **coords_stack, t_map *map);
t_fdf	*fdf_init(t_map *map);
void	draw_img(t_map *map, t_fdf *fdf);
double	percent(int start, int end, int current);
int		get_index(int x, int y, int width);
t_point	new_point(int x, int y, t_map *map);
int		ft_atoi_base(const char *str, int base);
t_bool	ft_isnumber(char *str, int base);
int		get_color(int z, t_map *map);
t_RGB	colorConverter(int hexValue);
t_RGB	avg_color(t_RGB color_f, t_RGB color_s);

#endif
