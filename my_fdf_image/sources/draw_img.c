/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:24:31 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/16 16:24:46 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_fdf type, t_point type, get_color(), WIDTH and HEIGHT macros,
** new_point()
** "libft.h" for ft_bzero() and ft_abs
** "mlx.h" for mlx_pixel_put()
** "color.h" for macro COLOR_BACKGROUND
*/

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "color.h"

/*
** Put pixel into map image
*/

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >=0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

/*
** Draw a line between points begin and end
** Delta values represent the distances between begin and end on x, y and z
** int pixels is the length of the line in pixels
** All points will successively be t_point pixel

static void	draw_line(t_fdf *fdf, t_point begin, t_point end, t_map *map)
{
	t_point	delta;
	int		pixels;
	t_point	pixel;

	delta.x = end.x - begin.x;
	delta.y = end.y - begin.y;
	delta.z = end.z - begin.z;
	pixels = ft_sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	delta.z /= pixels;
	pixel.x = begin.x;
	pixel.y = begin.y;
	pixel.z = begin.z;
	while (pixels)
	{
		put_pixel(fdf, pixel.x, pixel.y, \
		get_color(pixel.z, map));
		pixel.x += delta.x;
		pixel.y += delta.y;
		pixel.z += delta.z;
		pixels--;
	}
}*/

static void	draw_line(t_fdf *fdf, t_point f, t_point s)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = ft_abs(s.x - f.x);
	delta.y = ft_abs(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		put_pixel(fdf, cur.x, cur.y, get_line_color(f, s, cur));
		if ((error[1] = error[0] * 2) > -delta.y)
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
** Draw image
*/

void	draw_img(t_map *map, t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	begin;
	t_point	end;

	draw_background(fdf);
	set_proj_param(map, fdf);
	map->zoom = 0.8 * ft_imin((WIDTH * WIDTH) / ((map->x_max - map->x_min) * map->width), (WIDTH * WIDTH) / ((map->y_max - map->y_min) * map->height));
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
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
