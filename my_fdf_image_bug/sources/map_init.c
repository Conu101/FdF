/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:58:37 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/20 14:34:54 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_map type, terminate()
** "libft.h" for ft_memalloc(), NULL macros ("libft.h" includes <string.h>),
** "errors.h" for ERR_MAP_INIT macro
*/

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"
#include "../includes/errors.h"

/*
** Attribute all initial values to t_map element = initialize.
*/
t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!map)
		terminate(ERR_MAP_INIT);
	map->width = 0;
	map->height = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = 0;
	map->z_max = 0;
	map->z_range = 0;
	map->z_divisor = 1;
	map->zoom = 1;
	map->x_offset = 0;
	map->y_offset = 0;
	map->x_min = 0;
	map->x_max = 0;
	map->y_min = 0;
	map->y_max = 0;

	return (map);
}
