/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:40:02 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/20 12:35:58 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_point type and t_map type
** "libft.h" for t_putendl_fd()
** <stdlib.h> for exit()
*/

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>


/*
** Get index in array by x and y
*/

int		get_index(int x, int y, int width)
{
	return (y * width + x);
}


/*
** Create t_point element (x value + y value + z value + color value)
** get zoom in function of the map size and image size, center the map in the image
** give color in function of z altitude.
*/

t_point	new_point(int x, int y, t_map *map)
{
	t_point	point;
	int		index;

	index = get_index(x, y, map->width);
	map->zoom = ft_imin(WIDTH / map->width, HEIGHT / map->height);
	point.x = (x + 1) * map->zoom * 0.9 + (WIDTH - map->zoom * map->width) / 2;
	point.y = (y + 1) * map->zoom * 0.9 + (HEIGHT - map->zoom * map->height) / 2;
	point.z = map->coords_arr[index];
	point.color = (map->colors_arr[index] == -1) ?
			get_relative_color(point.z, map) : map->colors_arr[index];
	return (point);
}
