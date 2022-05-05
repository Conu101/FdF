/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:24:31 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/03 17:11:55 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_fdf type, t_point type, get_color(), WIDTH and HEIGHT macros,
** new_point()
** "libft.h" for ft_bzero()
** "mlx.h" for mlx_pixel_put()
*/

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

/*
** Draw a line between points f = first and s = second
** All points in between will successively be delta
*/

static void	draw_line(t_point f, t_point s, t_fdf *fdf)
{
	int		i;
	int		j;
	int		length;
	t_point	delta;
	int		delta_length;

	length = (s.x - f.x) + (s.y - f.y);
	j = f.y;
	while (j <= s.y)
	{
		i = f.x;
		while (i <= s.x)
		{
			delta.x = i;
			delta.y = j;
			delta_length = (delta.x - f.x) + (delta.y - f.y);
			delta.z = f.z + (delta_length / length) * (s.z - f.z);
			mlx_pixel_put(fdf->mlx, fdf->win, i, j, get_color(delta.z, \
			fdf->map));
			i++;
		}
		j++;
	}
}

/*
** Draw image
*/

void	draw_img(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != fdf->map->width - 1)
				draw_line(new_point(x, y, map), \
				new_point(x + 1, y, map), fdf);
			if (y != fdf->map->height - 1)
				draw_line(new_point(x, y, map), \
				new_point(x, y + 1, map), fdf);
			x++;
		}
		y++;
	}
}
