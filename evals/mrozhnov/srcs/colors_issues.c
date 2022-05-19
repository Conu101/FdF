/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_issues.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:11:26 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/05/18 19:11:10 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_key(int key, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (key == 53)
		exit(0);
	if (key == 82)
		handle_reset(mlx);
	if (key == 67)
		mlx->line->idle = !(mlx->line->idle);
	if (key == 75)
		mlx->line->colors = !(mlx->line->colors);
	if (key == 4)
		mlx->gui = !(mlx->gui);
	if (122 < key && key < 127)
		handle_offset(126 - key, mlx);
	if (key == 84 || key == 91 || key == 86 || key == 88 || \
			key == 89 || key == 92)
		check_rotation(key, mlx);
	if (key == 83 || key == 85)
		handle_pitch(key, mlx);
	if (key == 87)
		handle_iso(mlx);
	handle_drawing(mlx);
	return (0);
}

static void	handle_color_high(t_line *line, double d)
{
	int	color;
	int	i;

	i = -4;
	color = light_blue;
	if (d < 0.125)
		line->color = color >> (i + 3);
	else if (d < 0.25)
		line->color = color >> (i + 4);
	else if (d < 0.375)
		line->color = color >> (i + 5);
	else if (d < 0.5)
		line->color = color >> (i + 6);
	else if (d < 0.625)
		line->color = color >> (i + 7);
	else if (d < 0.75)
		line->color = color >> (i + 8);
	else if (d < 0.875)
		line->color = color >> (i + 9);
	else if (d <= 1)
		line->color = tangelo;
}

static void	handle_color_low(t_line *line, double d)
{
	int	color;
	int	i;

	i = -4;
	color = nice_blue;
	if (d > -0.125)
		line->color = color << (i + 3);
	else if (d > -0.25)
		line->color = color << (i + 4);
	else if (d > -0.375)
		line->color = color << (i + 5);
	else if (d > -0.5)
		line->color = color << (i + 6);
	else if (d > -0.625)
		line->color = color << (i + 7);
	else if (d > -0.75)
		line->color = color << (i + 8);
	else if (d > -0.875)
		line->color = color << (i + 9);
	else if (d >= -1)
		line->color = red;
}

void	handle_simple_color(t_line *line)
{
	if (line->z1 && line->z2)
	{
		if (line->z1 + line->z2 > 0)
			line->color = nice_blue;
		else
			line->color = red;
	}
	else if (line->z1 || line->z2)
	{
		if (line->z1 > 0 || line->z2 > 0)
			line->color = blue;
		else
			line->color = tangelo;
	}
	else
		line->color = orange;
}

void	handle_color(t_line *line, t_mlx *mlx)
{
	double	d;

	if (!line->colors)
	{
		handle_simple_color(line);
		return ;
	}
	d = (line->z1 + line->z2) / 2;
	d /= mlx->map->maxz;
	if (d > 0)
		handle_color_high(line, d);
	else if (d < 0)
		handle_color_low(line, d);
	else
		line->color = light_green;
}
