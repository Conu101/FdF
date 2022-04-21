/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:24:31 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/22 00:32:50 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_fdf type, t_point type, get_color(), WIDTH and HEIGHT macros
**  new_point()
** "libft.h" for FT_ABS macros and ft_bzero()
** "mlx.h" for mlx_put_image_to_window()
** "color.h" for BACKGROUND macro
*/

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "color.h"
//#include <math.h> forbidden

/*
** Get the color of the pixewl on the line depending on its altitude


static int	get_delta_color(t_fdf *fdf, t_point delta)
{
	int	min;
	int	max;

	min = fdf->map->z_min;
	max = fdf->map->z_max;
	if (delta.z <= (min + ((2/10) * (max - min))))
		delta.color = COLOR_SAFFRON;
	if (delta.z > (min + (2/10) * (max - min)) && delta.z <= (min + (4/10) * (max - min)))
		delta.color = COLOR_JAFFA;
	if (delta.z > (min + (4/10) * (max - min)) && delta.z <= (min + (6/10) * (max - min)))
		delta.color = COLOR_FLAMINGO;
	if (delta.z > (min + (6/10) * (max - min)) && delta.z <= (min + (8/10) * (max - min)))
		delta.color = COLOR_BRICK_RED;
	else
		delta.color = 0xEAEAEA;
	return (delta.color);
}*/


/*
** Draw line
*/

static void	draw_line(t_point f, t_point s, t_fdf *fdf)
{
	int		i;
	int		j;
	int		length;
	t_point	delta;
	int		delta_length;

	//length = sqrt((s.y - f.y) * (s.y - f.y) + (s.x - f.x) * (s.x - f.x));
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
			mlx_pixel_put(fdf->mlx, fdf->win, i, j, get_relative_color(delta.z, fdf->map));//0xFF32C3 
			i++;
		}
		j++;
	}
}

/*
static void	draw_line(t_point f, t_point s, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = FT_ABS(s.x - f.x);
	delta.y = FT_ABS(s.y - f.y);
	if (f.x < s.x)
		sign.x = 1;
	else 
		sign.x = -1;
	if (f.y < s.y)
		sign.y = 1;
	else 
		sign.y = -1;
	error[0] = delta.x - delta.y;
	error[1] = error[0] * 2;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		my_pixel_put(fdf, cur.x, cur.y, get_color(cur, f, s, delta));
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
			error[1] = error[0] * 2;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}
*/

/*
** Draw background color 


static void	draw_background(t_fdf *fdf)
{
	int	*image;
	int	i;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = BACKGROUND;
		i++;
	}
}


** Draw image
*/

void	draw_img(t_map *map, t_fdf *fdf)
{
	int		x;
	int		y;

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
