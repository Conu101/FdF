/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_arrays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:10:30 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/12 17:32:56 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_coord_val type, t_map type, terminate() and pop()
** "libft.h" for ssize_t type ("libft.h" includes <string.h>),
** size_t ("libft.h" includes <string.h>) and ft_memalloc()
** "error_message.h" for ERR_CONV_TO_ARR macros
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
	t_coord *top;

	top = NULL;
	if (coords_stack && *coords_stack)
	{
		top = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (top);
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
	if (!(map->coords_arr = (int *)ft_memalloc(arr_size)))
		terminate(ERR_CONV_TO_ARR);
	if (!(map->colors_arr = (int *)ft_memalloc(arr_size)))
		terminate(ERR_CONV_TO_ARR);
	i = map->width * map->height - 1;
	while ((coord = get_top(coords_stack)) && i >= 0)
	{
		map->coords_arr[i] = coord->z;
		map->colors_arr[i] = coord->color;
		if (coord->z > map->z_max)
			map->z_max = coord->z;
		if (coord->z < map->z_min)
			map->z_min = coord->z;
		i--;
		free(coord);
	}
	map->z_range = map->z_max - map->z_min;
}
