/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:57:31 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/19 17:30:36 by ctrouve          ###   ########.fr       */
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
** Change projection type: I (key 34) = iso; P (key 35) = parallel.
*/
static void	switch_projection(int keycode, t_fdf *fdf)
{
	if (keycode == 34)
		fdf->projection = 1;
	else if (keycode == 35)
		fdf->projection = 0;
	system("leaks fdf");
	draw_img(fdf->map, fdf);
}

/*
** React to key press
** Leaks can be tested with a line "system("leaks fdf");" before exit(1).
*/
static int		key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == 53)
	{	
		system("leaks fdf");
		exit(0);
	}
	else if (key == 34 || key == 35)
		switch_projection(key, fdf);
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
		build_coord_arrays(&coords_stack, map);
		draw_img(fdf->map, fdf);
		mlx_hook(fdf->win, 2, 0, key_press, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		terminate(ERR_USAGE);
	system("leaks fdf");
	exit(0);
}
