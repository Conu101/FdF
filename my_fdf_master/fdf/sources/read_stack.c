/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:06:45 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/05 15:49:04 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_coord_val type
** <stdlib.h> for NULL macros
*/

#include "fdf.h"
#include <stdlib.h>

/*
** Add t_coord_val element to stack
*/

void	build_coord_list(t_coord_val **coords_stack, t_coord_val *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

/*
** Get t_coord_val element from stack
*/

t_coord_val	*pop(t_coord_val **coords_stack)
{
	t_coord_val *top;

	top = NULL;
	if (coords_stack && *coords_stack)
	{
		top = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (top);
}
