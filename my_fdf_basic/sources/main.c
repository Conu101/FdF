/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:57:31 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/21 16:00:07 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_map type, t_coord type, t_fdf type, terminate(),
**  and fdf() functions in main
** "mlx.h" for mlx_destroy_window(), mlx_key_hook() and mlx_loop()
** "errors.h" for ERR macros
** <fcntl.h> for open() and O_RDONLY
** <stdlib> for exit
** <errno.h> for errno value
*/

#include "fdf.h"
#include "mlx.h"
#include "errors.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

/*
** esc or q key press event
*/

static int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_map		*map;
	t_coord		*coords_stack;
	t_fdf		*fdf;

	errno = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			terminate(ERR_MAP);
		map = map_init();
		if (map_populate(fd, &coords_stack, map) == -1)
			terminate(ERR_MAP_READING);
		fdf = fdf_init(map); 
		stack_to_arrays(&coords_stack, map);//norm checked until here
		draw_img(fdf->map, fdf);
		mlx_key_hook(fdf->win, key_hook, &fdf);
		mlx_loop(fdf->mlx);
	}
	else
		terminate(ERR_USAGE);
	return (0);
}
