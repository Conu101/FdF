/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:04:41 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/11 21:30:34 by ctrouve          ###   ########.fr       */
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
