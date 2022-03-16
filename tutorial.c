/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:26:12 by ctrouve           #+#    #+#             */
/*   Updated: 2022/03/16 14:37:10 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# include <math.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 360

int main()
{
	int	sig;

	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Tutorial Window - Draw Line");

	//draw_line(mlx, win, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, WINDOW_WIDTH/2, 0, 0xFF32C3);
	sig = 0;
	while (sig <= 360 && ((WINDOW_WIDTH/2) * sin(sig)) >= 0 && ((WINDOW_WIDTH/2) * sin(sig)) <= WINDOW_WIDTH \
	&& ((WINDOW_WIDTH/2) * (1 - cos(sig))) >= 0 && ((WINDOW_WIDTH/2) * (1 - cos(sig))) <= WINDOW_HEIGHT)
	{
		draw_line(mlx, win, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, WINDOW_WIDTH/2 + (WINDOW_WIDTH/2) * sin(sig), (WINDOW_WIDTH/2) * (1 - cos(sig)), 0xFF32C3);
		sig++;
	}

	mlx_loop(mlx);
}
