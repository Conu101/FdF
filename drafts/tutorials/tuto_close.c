/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuto_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:11:15 by ctrouve           #+#    #+#             */
/*   Updated: 2022/03/17 13:25:04 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# include <math.h>
# include <unistd.h>



#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 1200

int	main(void)
{
	t_vars	vars;
	int		sig;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");

	sig = 0;
	while (sig <= 360 && (WINDOW_WIDTH/2 + (WINDOW_WIDTH/2) * cos(sig)) >= 0 && (WINDOW_WIDTH/2 + (WINDOW_WIDTH/2) * cos(sig)) <= WINDOW_WIDTH \
	&& ((WINDOW_HEIGHT/2) * (1 - sin(sig))) >= 0 && ((WINDOW_HEIGHT/2) * (1 - sin(sig))) <= WINDOW_HEIGHT)
	{
		draw_line(vars.mlx, vars.win, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, WINDOW_WIDTH/2 + (WINDOW_WIDTH/2) * cos(sig), (WINDOW_HEIGHT/2) * (1 - sin(sig)), 0xFF32C3);
		sig++;
	}
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
