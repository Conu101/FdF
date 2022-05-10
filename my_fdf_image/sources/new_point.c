/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:40:02 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/10 18:05:07 by ctrouve          ###   ########.fr       */
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
** depending on the value of param int projection, change the projection
** if projection = 0, view parallel
** if projection = 1, view ISO

t_point	change_proj(t_point point, t_fdf *fdf, t_map *map)
{
	if (fdf->projection == 1)
		iso(&point.x, &point.y, point.z);
	map->zoom = ft_imin(WIDTH / map->width, HEIGHT / map->height);
	point.x = (point.x + 1) * map->zoom * 0.5 + WIDTH / 2;
	point.y = (point.y + 1) * map->zoom * 0.5 + HEIGHT / 3;
	return (point);
}
*/

/*
** Project coordinate to 2D plane
*/

t_point		project(t_point p, t_fdf *fdf)
{
	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	p.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	p.x -= (fdf->map->width * fdf->camera->zoom) / 2;
	p.y -= (fdf->map->height * fdf->camera->zoom) / 2;
	if (fdf->camera->projection == 1)
		iso(&p.x, &p.y, p.z);
	p.x += (WIDTH) / 2 + fdf->camera->x_offset;
	p.y += (HEIGHT + fdf->map->height * fdf->camera->zoom) / 2 \
	+ fdf->camera->y_offset;
	return (p);
}
