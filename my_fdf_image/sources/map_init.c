/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:58:37 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/20 14:41:53 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_map type, terminate()
** "libft.h" for ft_memalloc(), NULL macros ("libft.h" includes <string.h>)
** "errors.h" for ERR_MAP_INIT macro
*/

#include "fdf.h"
#include "libft.h"
#include "errors.h"

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
	map->zoom = 1;
	return (map);
}
