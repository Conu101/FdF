/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:11:15 by ctrouve           #+#    #+#             */
/*   Updated: 2022/03/18 11:43:31 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# include <math.h>
# include <unistd.h>
#include "./libft/libft.h"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 1200


void	print_coords(t_vars *vars)
{
	int		i;
	int		k;

	i = 0;
	while (vars->print[i] != NULL)
	{
		if (i < vars->totlen - vars->xlen)
		{
			k = i + vars->xlen;
			print_line(vars, vars->print[i], vars->print[k]);
		}
		if ((i + 1) % vars->xlen != 0)
		{
			k = i + 1;
			print_line(vars, vars->print[i], vars->print[k]);
		}
		i++;
	}
}

void	adjust_vars(t_vars *vars)
{
	int		i;

	i = 0;
	while (vars->print[i] != NULL)
	{
		vars->print[i]->xp = vars->print[i]->x;
		vars->print[i]->yp = vars->print[i]->y;
		vars->print[i]->xp = vars->print[i]->xp + (vars->print[i]->xp * vars->zoom);
		vars->print[i]->yp = vars->print[i]->yp + (vars->print[i]->yp * vars->zoom);
		vars->print[i]->hp = vars->print[i]->h * vars->depth;
		vars->print[i]->xp = (vars->const1 * vars->print[i]->xp) - (vars->const2 * \
				vars->print[i]->yp);
		vars->print[i]->yp = (vars->print[i]->h * vars->depth) + ((vars->const1 / 2) * \
				vars->print[i]->xp) + ((vars->const2 / 2) * vars->print[i]->yp);
		vars->print[i]->xp = vars->print[i]->xp + vars->xc;
		vars->print[i]->yp = vars->print[i]->yp + vars->yc;
		i++;
	}
}

void	set_vars(t_vars *vars)
{
	vars->zoom = 50;
	vars->xc = 300;
	vars->yc = 300;
	vars->const1 = 0.5;
	vars->const2 = 1;
	vars->depth = 0;
	vars->r = 1;
	vars->g = 100;
	vars->b = 200;
	vars->coloron = 0;
	vars->color = 0x00FFFFFF;
}

void	visualize(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Conu's fdf");
	/*set_vars(vars);
	adjust_vars(vars);
	print_coords(vars);
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0xFFFFFF, "Disco Mode = RETURN");
	mlx_string_put(vars->mlx, vars->win, 10, 30, 0xFFFFFF, "Move = <-, ->, up, down");
	mlx_string_put(vars->mlx, vars->win, 10, 50, 0xFFFFFF, "Depth = 1 & 3");
	mlx_string_put(vars->mlx, vars->win, 10, 70, 0xFFFFFF, "Tilt = 4 & 6");
	mlx_string_put(vars->mlx, vars->win, 10, 90, 0xFFFFFF, "Stretch = 8 & 2");
	mlx_string_put(vars->mlx, vars->win, 10, 110, 0xFFFFFF, "Zoom = - & +");*/
	mlx_key_hook(vars->win, key_actions, &vars);
	mlx_loop(vars->mlx);
}


int	main(int argc, char **argv)
{
	int		xlen;
	char	*str;
	t_vars	*vars;
	char	**grid;

	xlen = 0;
	if (argc != 2)
	{
		ft_putstr("Usage: ./fdf filename\n");
		return (0);
	}
	if (!(str = file_to_str(argv[1], xlen)))
		return (0);
	check_error(str);
	if (!(vars = (t_vars*)malloc(sizeof(t_vars))))
		return (0);
	vars->xlen = xlen;
	grid = ft_strsplit(str, ' ');
	ft_strdel(&str);
	vars->print = str_to_grid(vars, grid);
	vars->xlen = xlen;
	visualize(vars);
	return (0);
}
