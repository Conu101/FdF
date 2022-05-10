/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:55:03 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/10 18:06:47 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for terminate(), t_fdf type, WIDTH macros, HEIGHT macros,
** and t_camera type
** "libft.h" for ft_memalloc(), ft_imin()
** "errors.h" for ERR_CAMERA_INIT macro
*/

#include "fdf.h"
#include "libft.h"
#include "errors.h"

/*
** Initialize t_camera element
*/

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		terminate(ERR_CAMERA_INIT);
	camera->zoom = ft_imin(WIDTH / fdf->map->width / 2, HEIGHT / \
	fdf->map->height / 2);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->projection = 1;
	return (camera);
}
