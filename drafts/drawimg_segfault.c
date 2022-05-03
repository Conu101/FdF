/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:24:31 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/22 11:56:40 by ctrouve          ###   ########.fr       */
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

/*
** Put pixel into map image
** As each RGB pixel has three sets of 8-bit binary numbers it therefore has 
** 24 bits of computer information in total. Hence the term '24-bit colour'. 
** And as 8 bits equals 1 byte, each RGB pixel therefore equals 3 bytes in 
** file size.
** color, color >> 8, color >> 16 = bitwise notation to set the R, G, and B
** values of each pixel.
*/

static void	my_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

/*
** 
*/

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

/*
** Draw background color 
*/

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

/*
** Draw image
*/

void	draw_img(t_map *map, t_fdf *fdf)
{
	int		x;
	int		y;

	draw_background(fdf);
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
	mlx_put_image_to_window(fdf->mlx, fdf->win, \
	fdf->img, 0, 0);
}
