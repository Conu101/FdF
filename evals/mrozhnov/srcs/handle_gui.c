/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_gui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnov <mrozhnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:02:11 by mrozhnov          #+#    #+#             */
/*   Updated: 2022/05/19 14:56:02 by mrozhnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_gui_double(t_mlx *mlx, int x, int y, double d)
{
	char	*str;

	str = ft_itoa(d);
	mlx_string_put(mlx->init, mlx->window, x, y, white, str);
	free(str);
}

void	mlx_putstr(t_mlx *mlx, int x, int y, char *str)
{
	mlx_string_put(mlx->init, mlx->window, x, y, white, str);
}

void	draw_gui(t_mlx *mlx)
{
	if (!mlx->line->iso)
		mlx_putstr(mlx, 1140, 30, "Direct Projection");
	if (mlx->line->iso)
		mlx_putstr(mlx, 1140, 30, "Isometric Projection");
	mlx_putstr(mlx, 1450 - ft_strlen(mlx->map->name) * 10, 950, mlx->map->name);
	mlx_putstr(mlx, 1140, 75, "2 / 8 - Rotate X-axis");
	mlx_putstr(mlx, 1140, 100, "4 / 6 - Rotate Y-axis");
	mlx_putstr(mlx, 1140, 125, "7 / 9 - Rotate Z-axis");
	mlx_putstr(mlx, 1140, 150, "1 / 3 - Change Z-height");
	mlx_putstr(mlx, 1140, 195, "5 - Toggle view");
	mlx_putstr(mlx, 1140, 220, "0 - Reset view");
	mlx_putstr(mlx, 1140, 245, "* - Toggle autospin");
	mlx_putstr(mlx, 1140, 270, "/ - Toggle colours");
	mlx_putstr(mlx, 1140, 315, "Mouse wheel - Zoom in/out");
	mlx_putstr(mlx, 1140, 340, "Arrow keys - Move map");
	mlx_putstr(mlx, 1140, 385, "X-axis:");
	mlx_putstr(mlx, 1140, 410, "Y-axis:");
	mlx_putstr(mlx, 1140, 435, "Z-axis:");
	mlx_putstr(mlx, 1140, 460, "Z-height:");
	draw_gui_double(mlx, 1190, 385, mlx->line->rotatex * 57.33);
	draw_gui_double(mlx, 1190, 410, mlx->line->rotatey * 57.33);
	draw_gui_double(mlx, 1190, 435, mlx->line->rotatez * 57.33);
	draw_gui_double(mlx, 1190, 460, mlx->line->pitch);
}
