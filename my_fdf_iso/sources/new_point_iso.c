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
*/

static void	iso(t_point p)
{
	int previous_x;
	int previous_y;

	previous_x = p.x;
	previous_y = p.y;
	p.x = (previous_x - previous_y) * cos(0.523599) + 1;
	p.y = -(p.z) + (previous_x + previous_y) * sin(0.523599) + 2;
}

t_point	new_point_iso(int x, int y, t_map *map)
{
	t_point	point;
	int		index;

	index = get_index(x, y, map->width);
	map->zoom = ft_imin(WIDTH / map->width, HEIGHT / map->height);
	point.x = (x + 1) * map->zoom * 0.9 + (WIDTH - map->zoom * map->width) / 2;
	point.y = (y + 1) * map->zoom * 0.9 + (HEIGHT - map->zoom * map->height) \
	/ 2;
	point.z = map->coords_arr[index];
	iso(point);
	if (map->colors_arr[index] == -1)
		point.color = get_color(point.z, map);
	else
		point.color = map->colors_arr[index];
	return (point);
}
