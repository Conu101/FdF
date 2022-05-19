/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_proj_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:21:14 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/19 17:04:17 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_point type and t_map type
** "libft.h" for ft_abs(), ft_imin(), ft_imax()
*/

#include "fdf.h"
#include "libft.h"

/*
** Calculate z_divisor. z_div = z_range if both z_min and z_max 
** are same sign, otherwise z_div = smallest abs value.
*/
static double	z_div(t_map *map)
{
	double	z_div;

	z_div = 10 * map->z_range / ft_imin(map->width, map->height);
	return (z_div);
}

/*
** Calculate zoom so all points fit in the map
*/
static double	get_zoom(t_map *map)
{
	double	zoom;

	zoom = 0.75 * (ft_imin(WIDTH / map->width, HEIGHT / map->height));
	return (zoom);
}

/*
** Set zoom, x_and y_offset so that the image remains within
** 9/10 of the screen in all directions
*/

void	set_proj_param(t_map *map, t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	point;

	map->z_divisor = z_div(map);
	map->zoom = get_zoom(map);
	map->x_min = 0.1;
	map->x_max = map->width - 0.1;
	map->y_min = 0.1;
	map->y_max = map->height - 0.1;
	y = 0;
	while (y <= map->height - 1)
	{
		x = 0;
		while (x <= map->width - 1)
		{
			if (x < map->width & y < map->height)
			{
				point = change_proj(new_point(x, y, map), fdf, map);
				if (point.x <= map->x_min)
					map->x_min = point.x;
				if (point.x >= map->x_max)
					map->x_max = point.x;
				if (point.y <= map->y_min)
					map->y_min = point.y;
				if (point.y >= map->y_max)
					map->y_max = point.y;
			}
			x++;
		}
		y++;
	}
	map->x_offset = -map->x_min + (WIDTH - (map->x_max - map->x_min)) / 2;
	map->y_offset = -map->y_min + (HEIGHT - (map->y_max - map->y_min)) / 2;
}
