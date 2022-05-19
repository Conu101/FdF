/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_issues.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:39:14 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/05/18 20:08:31 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_background(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < WIN_WIDTH * WIN_HEIGHT * 4)
	{
		mlx->image[i] = (char)32;
		mlx->image[i + 1] = (char)32;
		mlx->image[i + 2] = (char)32;
		i += 4;
	}
}

static void	draw_line(t_line *line, t_mlx *mlx)
{
	int	*map;

	if (line->autooffset)
	{
		line->offsetx = 750 - mlx->map->cols / 2 * 5 - mlx->map->mapxy[0];
		line->offsety = 500 - mlx->map->lines / 2 * 5 - mlx->map->mapxy[1];
	}
	map = mlx->map->mapxy;
	handle_color(line, mlx);
	line->x1 = line->x1 * line->zoom;
	line->x2 = line->x2 * line->zoom;
	line->y1 = line->y1 * line->zoom;
	line->y2 = line->y2 * line->zoom;
	line->z1 = line->z1 * line->zoom * line->pitch;
	line->z2 = line->z2 * line->zoom * line->pitch;
	handle_transform(line);
	line->x1 = line->x1 + line->offsetx;
	line->x2 = line->x2 + line->offsetx;
	line->y1 = line->y1 + line->offsety;
	line->y2 = line->y2 + line->offsety;
	bresenham(line, mlx);
}

void	handle_line_draw(int xy[4], t_line *line, t_mlx *mlx)
{
	int	*map;

	map = mlx->map->mapxy;
	line->x1 = map[xy[0] * 3 + xy[2] * mlx->map->cols * 3];
	line->x2 = map[xy[1] * 3 + xy[3] * mlx->map->cols * 3];
	line->y1 = map[xy[0] * 3 + 1 + xy[2] * mlx->map->cols * 3];
	line->y2 = map[xy[1] * 3 + 1 + xy[3] * mlx->map->cols * 3];
	line->z1 = map[xy[0] * 3 + xy[2] * mlx->map->cols * 3 + 2];
	line->z2 = map[xy[1] * 3 + xy[3] * mlx->map->cols * 3 + 2];
	draw_line(line, mlx);
}

static void	draw_map(t_line *line, t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->map->lines)
	{
		x = 0;
		while (x < mlx->map->cols)
		{
			if (x + 1 < mlx->map->cols)
				handle_line_draw(((int [4]){x, x + 1, y, y}), line, mlx);
			if (y + 1 < mlx->map->lines)
				handle_line_draw(((int [4]){x, x, y, y + 1}), line, mlx);
			x++;
		}
		y++;
	}
}

int	handle_drawing(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	draw_background(mlx);
	draw_map(mlx->line, mlx);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->image_ptr, 0, 0);
	if (mlx->gui)
		draw_gui(mlx);
	mlx_putstr(mlx, 20, 20, "Press H to toggle GUI");
	return (0);
}
