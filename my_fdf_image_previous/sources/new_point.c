/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:40:02 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/18 12:58:38 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_point type and t_map type
** "libft.h" for t_putendl_fd(), ft_abs(), ft_imin()
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
*/

t_point	new_point(int x, int y, t_map *map)
{
	t_point	point;
	int		index;

	index = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->coords_arr[index];
	if (map->colors_arr[index] == -1)
		point.color = get_color(point.z, map);
	else
		point.color = map->colors_arr[index];
	return (point);
}

/*
** Convert coordinate to iso projection
*/

static void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

/*
** Calculate z_divisor. z_div = z_range if both z_min and z_max 
** are sane sign, otherwise z_div = smallest abs value.

static int	z_div(t_map *map)
{
	int	z_div;

	if (map->z_min >= 0 || map->z_max <= 0)
		z_div = 0.25 * map->z_range;
	else
		z_div = 0.5 * ft_imin(ft_abs(map->z_min), map->z_max);
	return (z_div);
}
*/
static double	z_div(t_map *map)
{
	int	z_div;

	z_div = map->z_range / 4;
	return (z_div);
}

/*
** depending on the value of param int projection, change the projection
** if projection = 0, view parallel
** if projection = 1, view ISO
*/

t_point	change_proj(t_point point, t_fdf *fdf, t_map *map)
{
	map->z_divisor = z_div(map);
	//point.x = point.x * map->zoom;
	//point.y = point.y * map->zoom;
	point.z = (point.z / map->z_divisor);// * map->zoom;
	if (fdf->projection == 1)
		iso(&point.x, &point.y, point.z);
	point.x = point.x + map->x_offset;
	point.y = point.y + map->y_offset;
	return (point);
}