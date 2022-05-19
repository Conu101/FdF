/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnov <mrozhnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:29:59 by mrozhnov          #+#    #+#             */
/*   Updated: 2022/05/19 17:09:22 by mrozhnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' \
			&& !ft_isdigit_neg(&line[i]))
			exit_msg(2);
		i++;
	}
}

static void	check_count(int count, t_map *map)
{
	if (!count)
		exit_msg(2);
	if (map->cols)
		if (count != map->cols)
			exit_msg(2);
}

static int	isoverflow(char *line)
{
	int	i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (i == 10)
	{
		if ((unsigned int) ft_atoi(&line[0]) > (unsigned int) 2 << 31)
			return (0);
	}
	return (i < 11);
}

int	line_len(char *line, t_map *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		if (ft_isdigit(line[i]) || ft_isdigit_neg(&line[i]))
		{
			if (line[i] == '-')
				i++;
			if (!(isoverflow(&line[i])))
				exit_msg(2);
			while (ft_isdigit(line[i]))
				i++;
			count++;
		}
	}
	check_count(count, map);
	return (count);
}
