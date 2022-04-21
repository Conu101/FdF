/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_arrays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:10:30 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/21 15:53:04 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_coord type, t_map type, terminate() and get_top()
** "libft.h" for ssize_t type ("libft.h" includes <string.h>),
** size_t ("libft.h" includes <string.h>) and ft_memalloc()
** "errors.h" for ERR_CONV_TO_ARR macro
** <stdlib.h> for free()
*/

#include "fdf.h"
#include "libft.h"
#include "errors.h"
#include <stdlib.h>

/*
** Get t_coord element from stack
*/

static t_coord	*get_top(t_coord **coords_stack)
{
	t_coord	*top;

	top = NULL;
	if (coords_stack && *coords_stack)
	{
		top = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (top);
}

/*
** Set parameter values of elem t_map * map
** Norm-compliance function, otherwise stack_to_arrays too long
*/

static void	set_map_param(t_map *map, t_coord *coord, ssize_t i)
{
	map->coords_arr[i] = coord->z;
	map->colors_arr[i] = coord->color;
	if (coord->z > map->z_max)
		map->z_max = coord->z;
	if (coord->z < map->z_min)
		map->z_min = coord->z;
}

/*
** Convert stack with t_coord elements (contains z value and color value)
** to array with z values and array with color values.
*/

void	stack_to_arrays(t_coord **coords_stack, t_map *map)
{
	t_coord	*coord;
	ssize_t	i;
	size_t	arr_size;

	arr_size = map->width * map->height * sizeof(int);
	map->coords_arr = (int *)ft_memalloc(arr_size);
	if (map->coords_arr == NULL)
		terminate(ERR_CONV_TO_ARR);
	map->colors_arr = (int *)ft_memalloc(arr_size);
	if (map->colors_arr == NULL)
		terminate(ERR_CONV_TO_ARR);
	coord = (t_coord *)ft_memalloc(sizeof(t_coord));
	if (coord == NULL)
		terminate(ERR_MAP_READING);
	else
		coord = get_top(coords_stack);
	i = map->width * map->height - 1;
	while ((coord) && i >= 0)
	{
		set_map_param(map, coord, i);
		i--;
		free(coord);
		coord = get_top(coords_stack);
	}
	map->z_range = map->z_max - map->z_min;
}
