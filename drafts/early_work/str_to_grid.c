/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:16:56 by ctrouve           #+#    #+#             */
/*   Updated: 2022/03/18 12:48:27 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

static t_coord	**xy_depth(t_coord **print, char **grid, t_vars *vars)
{
	int		col;
	int		row;
	int		i;
	t_coord *point;

	i = -1;
	row = 0;
	col = -1;
	while (grid[++i] != '\0')
	{
		col++;
		if (!(point = (t_coord*)malloc(sizeof(t_coord))))
			exit(0);
		point->x = col;
		point->y = row;
		if ((i + 1) % vars->xlen == 0)
		{
			row++;
			col = -1;
		}
		point->h = ft_atoi(grid[i]);
		print[i] = point;
	}
	print[i] = NULL;
	return (print);
}

t_coord	**str_to_grid(t_vars *vars, char **grid)
{
	t_coord		**print;
	int			totlen;

	totlen = 0;
	if (!(print = (t_coord**)malloc(sizeof(t_coord))))
	{
		ft_putstr("Error str_to_grid");
		exit(0);
	}
	xy_depth(print, grid, vars);
	while (print[totlen] != NULL)
		totlen++;
	vars->totlen = totlen;
	return (print);
}