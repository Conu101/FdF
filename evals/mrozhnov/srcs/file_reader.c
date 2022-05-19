/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnov <mrozhnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:58:49 by mrozhnov          #+#    #+#             */
/*   Updated: 2022/05/19 17:25:14 by mrozhnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_isdigit_neg(char *str)
{
	return (str[0] == '-' && ft_isdigit(str[1]));
}

static void	malloc_extra_line(t_map *map)
{
	int	**tmp;
	int	i;

	tmp = (int **)malloc(sizeof(int *) * (map->lines));
	ft_memcpy(tmp, map->map, sizeof(int **) * map->lines);
	if (map->lines)
		free(map->map);
	map->map = (int **)malloc(sizeof(int *) * (map->lines + 1));
	i = 0;
	while (i < map->lines)
	{
		map->map[i] = tmp[i];
		i++;
	}
	free(tmp);
}

static void	parse_map_line(char *line, t_map *map)
{
	int	i;
	int	col;
	int	len;

	i = 0;
	col = 0;
	check_line(line);
	len = line_len(line, map);
	map->map[map->lines] = (int *)malloc(sizeof(int) * len);
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i])
		{
			map->map[map->lines][col++] = ft_atoi(&line[i]);
			if (map->maxz < map->map[map->lines][col - 1])
				map->maxz = map->map[map->lines][col - 1];
		}
		while (line[i] != ' ' && line[i])
			i++;
	}
	map->lines++;
	map->cols = col;
}

void	parse_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		ret;

	map->name = ft_strdup(file);
	map->lines = 0;
	map->cols = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_msg(4);
	map->maxz = 1;
	ret = get_next_line(fd, &line);
	while (ret)
	{
		malloc_extra_line(map);
		parse_map_line(line, map);
		free(line);
		line = NULL;
		ret = get_next_line(fd, &line);
	}
	free(line);
	if (map->lines == 0)
		exit_msg(2);
	close(fd);
}
