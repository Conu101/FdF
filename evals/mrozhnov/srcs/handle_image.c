/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:35:03 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/05/18 23:16:10 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	map_to_coordinates(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	count;

	map->mapxy = (int *)malloc(4 * map->lines * map->cols * 3);
	i = -1;
	y = map->lines / 2 * -5;
	count = 0;
	while (++i < map->lines)
	{
		j = -1;
		x = map->cols / 2 * -5;
		while (++j < map->cols)
		{
			map->mapxy[count] = x;
			map->mapxy[count + 1] = y;
			map->mapxy[count + 2] = map->map[i][j];
			x += 5;
			count += 3;
		}
		y += 5;
	}
}

void	handle_image(t_map *map)
{
	t_mlx	*mlx;
	t_line	*line;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	line = (t_line *)malloc(sizeof(t_line));
	if (!line || ! mlx)
		exit_msg(3);
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, WIN_WIDTH, WIN_HEIGHT, map->name);
	mlx->image_ptr = mlx_new_image(mlx->init, WIN_WIDTH, WIN_HEIGHT);
	mlx->image = mlx_get_data_addr(mlx->image_ptr, &(mlx->bpp), \
		&(mlx->size_line), &(mlx->endian));
	mlx->map = map;
	mlx->line = line;
	initialize_line(mlx->line, mlx);
	mlx_hook(mlx->window, 2, 0, check_key, (void *)mlx);
	mlx_hook(mlx->window, 4, 0, mouse_press, (void *)mlx);
	mlx_hook(mlx->window, 5, 0, mouse_release, (void *)mlx);
	mlx_hook(mlx->window, 6, 0, mouse_move, (void *)mlx);
	mlx_hook(mlx->window, 12, 0, handle_rotation, (void *)mlx);
	mlx_loop_hook(mlx->init, handle_rotation, (void *)mlx);
	map_to_coordinates(mlx->map);
	handle_drawing((void *)mlx);
	mlx_loop(mlx->init);
}

void	initialize_line(t_line *line, t_mlx *mlx)
{
	(void)mlx;
	mlx->mouse1 = 0;
	mlx->mouse2 = 0;
	line->color = white;
	line->zoom = 800 / (mlx->map->cols * 5);
	if (!line->zoom)
		line->zoom = 1;
	line->offsetx = 750;
	line->offsety = 500;
	line->iso = 0;
	line->pitch = 1;
	if (mlx->map->maxz > 20)
		line->pitch = 0.1;
	line->rotatex = 6;
	line->rotatey = 0;
	line->rotatez = 0;
	line->autooffset = 0;
	line->colors = 1;
	line->idle = 1;
	mlx->gui = 1;
}
