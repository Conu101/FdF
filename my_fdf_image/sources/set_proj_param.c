/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_proj_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:21:14 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/18 12:34:44 by ctrouve          ###   ########.fr       */
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
*/

void	set_proj_param(t_map *map, t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	point;
	int		resize;

	map->x_min = 0.1;
	map->x_max = map->width - 0.1;
	map->y_min = 0.1;
	map->y_max = map->height - 0.1;
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
	//map->x_offset = 0.3 * (ft_imin(map->width, map->height)) - map->x_min;
	//map->y_offset = 0.3 * (ft_imin(map->width, map->height)) - map->y_min;
	resize = ft_imin(map->width / ft_abs(map->x_max - map->x_min), \
	map->height / ft_abs(map->y_max - map->y_min));
	map->zoom = 0.8 * resize * (ft_imin(WIDTH / map->width, HEIGHT / map->height));
}
