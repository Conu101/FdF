/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:24:31 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/06 18:03:28 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_fdf type, t_point type, get_color(), WIDTH and HEIGHT macros,
** new_point()
** "libft.h" for ft_bzero()
** "mlx.h" for mlx_pixel_put()
*/

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

/*
** Draw a line between points begin and end
** Delta values represent the distances between begin and end on x, y and z
** int pixels is the length of the line in pixels
** All points will successively be t_point pixel
*/

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
		mlx_pixel_put(fdf->mlx, fdf->win, pixel.x, pixel.y, \
		get_color(pixel.z, map));
		pixel.x += delta.x;
		pixel.y += delta.y;
		pixel.z += delta.z;
		pixels--;
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

	y = 0;
	while (++y <= map->height - 1)
	{
		x = 0;
		while (++x <= map->width - 1)
		{
			if (x < map->width - 1)
			{
				begin = new_point_iso(x, y, map);
				end = new_point_iso(x + 1, y, map);
				draw_line(fdf, begin, end, map);
			}
			if (y < map->height - 1)
			{
				begin = new_point_iso(x, y, map);
				end = new_point_iso(x, y + 1, map);
				draw_line(fdf, begin, end, map);
			}
		}
	}
}
