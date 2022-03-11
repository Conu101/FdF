/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:26:12 by ctrouve           #+#    #+#             */
/*   Updated: 2022/03/11 14:02:25 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "mlx.h"

to initialize MiniLibX and open a simple empty window 

int main()
{
	void *mlx = mlx_init();
	mlx_new_window(mlx, 640, 360, "Tutorial Window");
	mlx_loop(mlx);
}
*/

/* to draw a single pixel in the middle of the  window 

int main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Draw Pixel");

	mlx_pixel_put(mlx, win, 640/2, 360/2, 0xFFFFFF);

	mlx_loop(mlx);
}
*/

#include <stdlib.h>
#include "mlx.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (MLX_ERROR);
	}
	mlx_pixel_put(mlx_ptr, win_ptr, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0xFFFFFF);
	
	// mlx_loop(mlx_ptr);

	mlx_destroy_window(mlx_ptr, win_ptr);
	free(mlx_ptr);
}