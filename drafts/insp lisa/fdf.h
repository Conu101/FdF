/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:13:53 by ctrouve           #+#    #+#             */
/*   Updated: 2022/03/18 11:43:00 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>


typedef struct		s_coord {
	int				x;
	int				xp;
	int				y;
	int				yp;
	int				h;
	int				hp;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_coord;

typedef struct		s_line {
	int				dx;
	int				dy;
	int				i;
	int				f;
	int				incx;
	int				incy;
	int				inc1;
	int				inc2;
	int				x;
	int				y;
}					t_line;

typedef struct	s_vars {
	void			*mlx;
	void			*win;
	t_coord			**print;
	int				depth;
	int				zoom;
	float			const1;
	float			const2;
	int				totlen;
	int				xlen;
	int				xc;
	int				yc;
	int				coloron;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	color;
}				t_vars;


int	rgb_to_int(double r, double g, double b);

int	draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);

int	key_actions(int keycode, t_vars *vars);

char	*file_to_str(char *file, int xlen);

t_coord	**str_to_grid(t_vars *vars, char **grid);

void	print_line(t_vars *vars, t_coord *first, t_coord *last);

void	check_error(char *str);

# endif
