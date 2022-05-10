/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:04:41 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/05 21:36:59 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_map and t_RGB types
** "color.h" for COLOR_*** macros
** "errors.h" for ERR_CONV_COLOR macro
** "libft.h" for ft_strjoin, ft_atoi, ft_itoa
*/

#include "fdf.h"
#include "color.h"
#include "errors.h"
#include "libft.h"

/*
** Get percent
*/

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

/*
** Get color from default palette. Color depends on altitude
*/

int	get_color(int z, t_map *map)
{
	double	percentage;

	percentage = percent(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (COLOR_VIOLET);
	else if (percentage < 0.4)
		return (COLOR_RED);
	else if (percentage < 0.6)
		return (COLOR_PINK);
	else if (percentage < 0.8)
		return (COLOR_ORANGE);
	else
		return (COLOR_YELLOW);
}

/*
** Get line color between 2 points. Color depends on the relative altitude 
** of both points and will be an average of their colors.


t_RGB	colorConverter(int hexValue)
{
	t_RGB	RGB_color;
	RGB_color.R = ((hexValue >> 16) & 0xFF) / 255.0;
	RGB_color.G = ((hexValue >> 8) & 0xFF) / 255.0;
	RGB_color.B = ((hexValue) & 0xFF) / 255.0;

	return RGB_color; 
}

t_RGB	avg_color(t_RGB color_f, t_RGB color_s)
{
	t_RGB	color_mid;

	color_mid.R = (color_f.R + color_s.R) / 2;
	color_mid.G = (color_f.G + color_s.G) / 2;
	color_mid.B = (color_f.B + color_s.B) / 2;

	return color_mid; 
}
*/