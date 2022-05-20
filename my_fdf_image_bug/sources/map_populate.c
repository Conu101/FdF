/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_populate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:52:25 by ctrouve           #+#    #+#             */
/*   Updated: 2022/05/20 14:35:43 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_coord type, terminate(), ft_isnumber(), ft_atoi_base(),
**  t_map type
** "libft.h" for size_t type ("libft.h" includes <string.h>), ft_memalloc()
**  ft_strsplit(), ft_atoi(), NULL macros ("libft.h" includes <string.h>)
**  and ft_strdel()
** "get_next_line.h" for get_next_line()
** "errors.h" for ERR_MAP_READING and ERR_MAP macros
** <stdlib.h> for free()
*/

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/errors.h"
#include <stdlib.h>

/*
** Free array that was returned by ft_strsplit()
*/

static void	free_strsplit_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/*
** Create t_coord element with information about z and color value
*/

static t_coord	*new_coord(char *s)
{
	t_coord	*coord;
	char	**parts;

	coord = (t_coord *)ft_memalloc(sizeof(t_coord));
	if (coord == NULL)
		terminate(ERR_MAP_READING);
	parts = ft_strsplit(s, ',');
	if (parts == NULL)
		terminate(ERR_MAP_READING);
	if (!ft_isnumber(parts[0], 10))
		terminate(ERR_MAP_READING);
	if (parts[1] && !ft_isnumber(parts[1], 16))
		terminate(ERR_MAP_READING);
	coord->z = ft_atoi(parts[0]);
	coord->color = -1;
	if (parts[1])
		coord->color = ft_atoi_base(parts[1], 16);
	coord->next = NULL;
	free_strsplit_arr(parts);
	return (coord);
}

/*
** Add t_coord element to stack
*/

static void	build_coord_list(t_coord **coords_stack, t_coord *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

/*
** Get coordinate values from line, create t_coord elements
** and add them to stack
*/

static void	parse_line(char **coords_line, t_coord **coords_stack, \
t_map *map)
{
	int	width;

	width = 0;
	while (*coords_line)
	{
		build_coord_list(coords_stack, new_coord(*(coords_line++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width)
		terminate(ERR_MAP);
}

/*
** Read map from file line by line and check if valid, set map height.
*/

int	map_populate(const int fd, t_coord **coords_stack, t_map *map)
{
	char	*line;
	int		gnl_ret;
	char	**coords_line;

	gnl_ret = get_next_line(fd, &line);
	while (gnl_ret == 1)
	{
		coords_line = ft_strsplit(line, ' ');
		if (coords_line == NULL)
			terminate(ERR_MAP_READING);
		parse_line(coords_line, coords_stack, map);
		free_strsplit_arr(coords_line);
		ft_strdel(&line);
		map->height++;
		gnl_ret = get_next_line(fd, &line);
	}
	if (!(*coords_stack))
		terminate(ERR_MAP);
	free(line);
	return (gnl_ret);
}
