/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:14:19 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/31 14:19:41 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_map type, terminate(), t_fdf type, WIDTH and HEIGHT macros
** "libft.h" for ft_memalloc(), NULL macros ("libft.h" includes <string.h>)
** "mlx.h" for mlx_init() and mlx_new_window()
** "errors.h" for ERR_FDF_INIT macro
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

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	if (fdf == NULL)
		terminate(ERR_FDF_INIT);
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		terminate(ERR_FDF_INIT);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF Conu");
	if (fdf->win == NULL)
		terminate(ERR_FDF_INIT);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (fdf->img == NULL)
		terminate(ERR_FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel), \
					&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	fdf->projection = 0;
	return (fdf);
}
