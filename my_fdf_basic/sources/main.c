/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:57:31 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/18 17:05:18 by ctrouve 
         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** stdlib for exit
*/

#include "fdf.h"
#include "mlx.h"
#include "errors.h"

#include <sys/errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
** esc key press event
*/

static int	key_hook(int keycode, t_fdf *fdf)
{
	if(keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(1);
	}
	return (0);
}

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
			mlx_key_hook(fdf->win, key_hook, &fdf);
			mlx_loop(fdf->mlx);
		}
	else
		terminate(ERR_USAGE);
	return (0);
}
