/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fdf_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:58:37 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/12 17:36:12 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_map type, terminate(), t_fdf type, WIDTH macros, HEIGHT macros
** "libft.h" for ft_memalloc(), NULL macros ("libft.h" includes <string.h>)
** "mlx.h" for mlx_init(), mlx_new_window(), mlx_new_image()
**  and mlx_get_data_addr()
** "error_message.h" for ERR_MAP_INIT macros and ERR_FDF_INIT macros
*/

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "errors.h"

/*
** Attribute all initial values to t_map element = initialize.
*/
t_map	*map_init(void)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		terminate(ERR_MAP_INIT);
	map->width = 0;
	map->height = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = 0;
	map->z_max = 0;
	map->z_range = 0;
	return (map);
}
