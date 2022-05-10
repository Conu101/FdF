/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_point_iso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:40:02 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/06 13:28:34 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_point type and t_map type
** "libft.h" for t_putendl_fd()
** <stdlib.h> for exit()
** <math.h> for cos and sin
*/

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <math.h>

/*
** Get index in array by x and y
*/

int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

/*
** Create t_point element (x value + y value + z value + color value)
** Get zoom in function of the map size and image size, center the map in the 
** image.
** Give color to point in function of z altitude.

static void	get_iso(t_point point)
{
	int previous_x;
	int previous_y;

	previous_x = point.x;
	previous_y = point.y;
	point.x = (previous_x - previous_y) * cos(0.523599);
	point.y = -(point.z) + (previous_x + previous_y) * sin(0.523599);
}*/


t_point	new_point_iso(int x, int y, t_map *map)
{
	t_point	point;
	int		index;

	index = get_index(x, y, map->width);
	map->zoom = ft_imin(WIDTH / map->width, HEIGHT / map->height);
	point.z = map->coords_arr[index];
	point.x = x * cos(30) - y * sin(30);
	point.y = -(point.z / 10) + x * cos(30) + y * sin(30);
	point.x = (point.x + 1) * map->zoom * 0.1 + (WIDTH - map->zoom * map->width) / 2;
	point.y = (point.y + 1) * map->zoom * 0.1 + (HEIGHT - map->zoom * map->height) \
	/ 2;
	if (map->colors_arr[index] == -1)
		point.color = get_color(point.z, map);
	else
		point.color = map->colors_arr[index];
	return (point);
}
