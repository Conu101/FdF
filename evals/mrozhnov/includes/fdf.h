/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnov <mrozhnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:17:57 by mrozhnov          #+#    #+#             */
/*   Updated: 2022/05/19 14:41:48 by mrozhnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <math.h>
# include <unistd.h>

# define WIN_HEIGHT	1000
# define WIN_WIDTH	1500

typedef struct map
{
	int				**map;
	int				*mapxy;
	int				cols;
	int				lines;
	int				maxz;
	char			*name;
}			t_map;

typedef struct s_line
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				z1;
	int				z2;
	int				color;
	double			zoom;
	int				autooffset;
	int				offsetx;
	int				offsety;
	int				iso;
	double			pitch;
	double			rotatex;
	double			rotatey;
	double			rotatez;
	int				colors;
	int				idle;

}			t_line;

typedef struct s_mlx
{
	void			*init;
	void			*window;
	void			*image_ptr;
	char			*image;
	int				bpp;
	int				size_line;
	int				endian;
	int				mouse1;
	int				mouse2;
	int				mousex;
	int				mousey;
	int				gui;
	t_map			*map;
	t_line			*line;

}			t_mlx;

enum e_color
{
	black = 0x0,
	white = 0xFFFFFF,
	red = 0xFF0000,
	green = 0x27E11E,
	light_green = 0xA4FFA4,
	emerald = 0x40E191,
	good_green = 0x91E140,
	blue = 0x0000FF,
	nice_blue = 0x2621FF,
	light_blue = 0x007CFF,
	orange = 0xFF8300,
	tangelo = 0xF94D00,
	yellow = 0xFFFF56
};

/***parse and check the file && store a map ***/
void				parse_map(char *file, t_map *map);
void				check_line(char *line);
int					ft_isdigit_neg(char *str);
int					line_len(char *line, t_map *map);
int					handle_drawing(void *param);

/*** creat image and drawing the map ***/
void				handle_image(t_map *map);
void				handle_color(t_line *line, t_mlx *mlx);
void				mlx_putstr(t_mlx *mlx, int x, int y, char *str);

/*** drawing ***/
void				bresenham(t_line *line, t_mlx *mlx);
void				draw_gui(t_mlx *mlx);

/*** transformation issues ***/
void				handle_transform(t_line *line);
void				check_360(t_line *line);
int					handle_rotation(t_mlx *mlx);
void				handle_offset(int dir, t_mlx *mlx);
void				handle_pitch(int key, t_mlx *mlx);
void				handle_rotatex(int key, t_mlx *mlx);
void				handle_rotatey(int key, t_mlx *mlx);
void				handle_rotatez(int key, t_mlx *mlx);
void				check_rotation(int key, t_mlx *mlx);
void				handle_reset(t_mlx *mlx);
void				handle_iso(t_mlx *mlx);
int					check_key(int key, void *param);
int					mouse_press(int key, int x, int y, void *param);
int					mouse_release(int key, int x, int y, void *param);
void				handle_mouse1_move(int x, int y, t_mlx *mlx);
void				handle_mouse2_move(int x, int y, t_mlx *mlx);
int					mouse_move(int x, int y, void *param);

/*** helpers ***/
void				exit_msg(int code);
void				initialize_line(t_line *line, t_mlx *mlx);

#endif
