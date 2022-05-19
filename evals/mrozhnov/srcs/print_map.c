/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:48:10 by mrozhnov          #+#    #+#             */
/*   Updated: 2022/05/19 10:13:25 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->cols)
		{
			write(1, &map->map[i][j++], map->cols);
		}
		write(1, "\n", 1);
		i++;
	}
}
