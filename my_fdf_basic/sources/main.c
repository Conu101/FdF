/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:57:31 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/12 17:16:58 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "errors.h"

#include <sys/errno.h>
#include <fcntl.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	int			fd;
	t_map		*map;
	t_coord		*coords_stack;
	t_fdf		*fdf;
	
	errno = 0;
	if (argc == 2)
		{
			if ((fd = open(argv[1], O_RDONLY)) < 0)
				terminate(ERR_MAP);
			map = map_init();
			if (map_populate(fd, &coords_stack, map) == -1)
				terminate(ERR_MAP_READING);
			fdf = fdf_init(map);
			stack_to_arrays(&coords_stack, map);
			draw_img(fdf->map, fdf);
			mlx_hook(fdf->win, 2, 1L<<0, close, &fdf);
			mlx_loop(fdf->mlx);
		}
	else
		terminate(ERR_USAGE);
	return (0);
}
