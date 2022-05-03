/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:24:09 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/03 19:24:34 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "color.h"

/*
if key event key press "i"

set all pixels to black

draw_img_iso

	all black
	same but with iso coord
*/

static void	draw_background(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((x != fdf->map->width - 1) && (y != fdf->map->height - 1))
				mlx_pixel_put(fdf->mlx, fdf->win, x, y, COLOR_BLACK);
			x++;
		}
		y++;
	}
}

/*
** Convert coordinate to iso projection

static void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}
*/

static t_point	new_point_iso(int x, int y, t_map *map)
{
	t_point	point;
	int		index;

	index = get_index(x, y, map->width);
	map->zoom = ft_imin(WIDTH / map->width, HEIGHT / map->height);
	point.z = map->coords_arr[index];
	point.x = (((x + 1) * map->zoom * 0.9 + (WIDTH - map->zoom * map->width) \
	/ 2) - ((y + 1) * map->zoom * 0.9 + (HEIGHT - map->zoom * map->height) \
	/ 2)) * cos(0.523599);
	point.y = -point.z + (((x + 1) * map->zoom * 0.9 + (WIDTH - map->zoom \
	* map->width) / 2) + ((y + 1) * map->zoom * 0.9 + (HEIGHT - map->zoom \
	* map->height) / 2)) * cos(0.523599);
	point.y = (y + 1) * map->zoom * 0.9 + (HEIGHT - map->zoom * map->height) \
	/ 2;
	if (map->colors_arr[index] == -1)
		point.color = get_color(point.z, map);
	else
		point.color = map->colors_arr[index];
	return (point);
}

/*
** Draw a line between points f = first and s = second
** All points in between will successively be delta
*/

static void	draw_line_iso(t_point f, t_point s, t_fdf *fdf)
{
	int		i;
	int		j;
	int		length;
	t_point	delta;
	int		delta_length;

	length = (s.x - f.x) + (s.y - f.y);
	j = f.y;
	while (j <= s.y)
	{
		i = f.x;
		while (i <= s.x)
		{
			delta.x = i;
			delta.y = j;
			delta_length = (delta.x - f.x) + (delta.y - f.y);
			delta.z = f.z + (delta_length / length) * (s.z - f.z);
			mlx_pixel_put(fdf->mlx, fdf->win, i, j, get_color(delta.z, \
			fdf->map));
			i++;
		}
		j++;
	}
}

void	draw_img_iso(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	draw_background(map, fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != fdf->map->width - 1)
				draw_line_iso(new_point_iso(x, y, map), \
				new_point_iso(x + 1, y, map), fdf);
			if (y != fdf->map->height - 1)
				draw_line_iso(new_point_iso(x, y, map), \
				new_point_iso(x, y + 1, map), fdf);
			x++;
		}
		y++;
	}
}
