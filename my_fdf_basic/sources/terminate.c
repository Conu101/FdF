/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:36:23 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/12 17:33:59 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_point type and t_map type
** "libft.h" for t_putendl_fd()
** <stdlib.h> for exit()
** <stdio.h> for perror()
** <errno.h> for errno value
*/

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/*
** Terminate execution and display error message
*/

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

/*
** Close program when called (for ex. key press).
int	close_prgm(int keycode, t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	return (0);
}
*/
