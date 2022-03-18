/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuto_draw_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:26:12 by ctrouve           #+#    #+#             */
/*   Updated: 2022/03/16 13:13:09 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <mlx.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 360

int main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Tutorial Window - Draw Pixel");

	mlx_pixel_put(mlx, win, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0xFF32C3);

	mlx_loop(mlx);
}
