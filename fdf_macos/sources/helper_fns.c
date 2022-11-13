/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:36:23 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/23 16:08:45 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "libft.h" for t_putendl_fd()
** <stdlib.h> for exit()
** <stdio.h> for perror()
** fdf.h for t_point type
*/

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

/*
** Terminate execution and display error message either from pre-defined error 
** types (macros) or if errno != 0, perror message.
*/

void	terminate(char *s)
{
	perror(s);
	exit(1);
}

/*
** helper fns for draw_line()
*/
t_point	set_delta(t_point f, t_point s)
{
	t_point	delta;

	delta.x = ft_abs(s.x - f.x);
	delta.y = ft_abs(s.y - f.y);
	return (delta);
}

int	comp(int a, int b)
{
	int	sign;

	if (a < b)
	{
		sign = 1;
	}
	else
	{
		sign = -1;
	}
	return (sign);
}
