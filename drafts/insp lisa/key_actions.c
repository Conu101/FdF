/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:11:15 by ctrouve           #+#    #+#             */
/*   Updated: 2022/03/17 16:58:06 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# include <stdlib.h>

/*
** the program quits if we press either 'esc' or 'q' key.
*/

int	key_actions(int keycode, t_vars *vars)
{
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->print);
		free(vars);
		exit(0);
	}
	return (0);
}
