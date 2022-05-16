/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_proj_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:21:14 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/16 16:34:34 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_point type and t_map type
** "libft.h" for ft_abs(), ft_imin(), ft_imax()
*/

#include "fdf.h"
#include "libft.h"

/*
** Set zoom, x_and y_offset so that the image remains within
** 9/10 of the screen in all directions

x = 0, y = map_height
x = map_width, y = 0 



static void	calculate(t_point point, t_map *map)
{
	if (point.x <= 0.1 * WIDTH)
		map->x_offset = ft_abs(point.x) + 0.1 * WIDTH;
	if (point.x >= 0.9 * WIDTH)
		map->zoom = map->zoom * ((0.9 * WIDTH) / point.x);
	if (point.y <= 0.1 * HEIGHT)
		map->y_offset = -ft_abs(point.y) + 0.1 * HEIGHT;
	if (point.y >= 0.9 * HEIGHT)
		map->zoom = map->zoom * ((0.9 * HEIGHT) / point.y);
}

void	set_proj_param(t_map *map, t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	point;

	map->zoom = ft_imin(WIDTH / map->width, HEIGHT / map->height);
	x = 0;
	y = 0;
	point = change_proj(new_point(x, y, map), fdf, map);
	calculate (point, map);
	x = map->width;
	y = 0;
	point = change_proj(new_point(x, y, map), fdf, map);
	calculate (point, map);
}
*/

void	set_proj_param(t_map *map, t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	point;
	int		resize;

	map->zoom = 0.9 * ft_imin(WIDTH / map->width, HEIGHT / map->height);
	y = 0;
	while (++y <= map->height - 1)
	{
		x = 0;
		while (++x <= map->width - 1)
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
		}
	}
	resize = ft_imax(ft_abs(map->x_max - map->x_min), \
	ft_abs(map->y_max - map->y_min)) / (HEIGHT);
	//map->zoom = ft_imin(WIDTH / map->width, HEIGHT / map->height);
	//map->zoom = resize * ft_imin(WIDTH / map->width, HEIGHT / map->height);
	map->x_offset = (0.1 * resize - map->x_min);
	map->y_offset = (0.1 * resize - map->y_min);
}
