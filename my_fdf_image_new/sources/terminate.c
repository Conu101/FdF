/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:36:23 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/20 17:00:41 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "libft.h" for t_putendl_fd()
** <stdlib.h> for exit()
** <stdio.h> for perror()
** <errno.h> for errno value
*/

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
//#include <errno.h>

/*
** Terminate execution and display error message either from pre-defined error 
** types (macros) or if errno != 0, perror message.
*/

void	terminate(char *s)
{
	//if (errno == 0)
	//	ft_putendl_fd(s, 2);
	//else
		perror(s);
	exit(1);
}
