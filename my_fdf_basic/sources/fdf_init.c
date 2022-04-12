/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:14:19 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/12 17:08:23 by ctrouve          ###   ########.fr       */
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
** Initialize t_fdf element
*/

t_fdf	*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		terminate(ERR_FDF_INIT);
	if (!(fdf->mlx = mlx_init()))
		terminate(ERR_FDF_INIT);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF Conu")))
		terminate(ERR_FDF_INIT);
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		terminate(ERR_FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
										&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	return (fdf);
}