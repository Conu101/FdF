/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:24:31 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/23 16:11:01 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_fdf type, t_point type, get_color(), WIDTH and HEIGHT macros,
** new_point() and comp()
** "libft.h" for ft_bzero() and ft_abs
** "mlx.h" for mlx_pixel_put() in case work out of school
** "color.h" for macro COLOR_BACKGROUND
*/

#include "fdf.h"
#include "libft.h"
#include "color.h"
//#include "mlx.h"

/*
** Put pixel into map image
*/

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

/*
** Draw line between 2 points. comp() and set_delta() are in the 
** tab "helper_fns"
** comp() gives a result of 1 or -1 depending if f.x>s.x or not
** set_delta() sets for delta.x and delta.y the abs value of s.x-f.x
** and s.y-f.y
*/

static void	draw_line(t_fdf *fdf, t_point f, t_point s)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta = set_delta(f, s);
	sign.x = comp(f.x, s.x);
	sign.y = comp(f.y, s.y);
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		put_pixel(fdf, cur.x, cur.y, get_line_color(f, s, cur));
		error[1] = error[0] * 2;
		if ((error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

/*
** Draw background uniform color
*/

static void	draw_background(t_fdf *fdf)
{
	int	*image;
	int	i;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = COLOR_BACKGROUND;
		i++;
	}
}

/*
** Draw grid within background
*/
static void	draw_grid(t_map *map, t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	begin;
	t_point	end;

	y = 0;
	while (++y <= map->height - 1)
	{
		x = 0;
		while (++x <= map->width - 1)
		{
			if (x < map->width - 1)
			{
				begin = change_proj(new_point(x, y, map), fdf, map);
				end = change_proj(new_point(x + 1, y, map), fdf, map);
				draw_line(fdf, begin, end);
			}
			if (y < map->height - 1)
			{
				begin = change_proj(new_point(x, y, map), fdf, map);
				end = change_proj(new_point(x, y + 1, map), fdf, map);
				draw_line(fdf, begin, end);
			}
		}
	}
}

/*
** Draw image
*/
void	draw_img(t_map *map, t_fdf *fdf)
{
	draw_background(fdf);
	set_proj_param(map, fdf);
	draw_grid(map, fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
