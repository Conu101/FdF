/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:57:31 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/23 17:53:02 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_map type, t_coord type, t_fdf type, terminate(),
**  and fdf() functions in main
** "mlx.h" for mlx_destroy_window(), mlx_key_hook() and mlx_loop() if out of
** school -> use the other Makefile
** "errors.h" for ERR macros
** <fcntl.h> for open() and O_RDONLY
** <stdlib> for exit
*/

//#include "mlx.h"
#include "fdf.h"
#include "errors.h"
#include <fcntl.h>
#include <stdlib.h>

/*
** Change projection type: I (key 34) = iso; P (key 35) = parallel.
** Leaks can be tested with a line "system("leaks fdf");" before draw_img()
** line 40.
*/
static void	switch_projection(int keycode, t_fdf *fdf)
{
	if (keycode == 34)
		fdf->projection = 1;
	else if (keycode == 35)
		fdf->projection = 0;
	draw_img(fdf->map, fdf);
}

/*
** React to key press to either switch projection or close the prgm.
** Leaks can be tested with a line "system("leaks fdf");" before exit(0) 
** line 55.
*/
static int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == 53)
	{
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
	exit(0);
}
