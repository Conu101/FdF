/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:48:32 by ctrouve           #+#    #+#             */
/*   Updated: 2022/03/18 11:42:42 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"
# include <fcntl.h>

char	*file_to_str(char *file, int xlen)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(0);
	tmp = ft_strnew(0);
	while (ret != 0)
	{
		line = ft_strnew(0);
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (NULL);
		xlen = (xlen == 0) ? ft_count_words(line, ' ') : xlen;
		if ((xlen != ft_count_words(line, ' ') && ret != 0) || xlen == 0)
			return (NULL);
		tmp = ft_strjoin(tmp, " ");
		tmp = ft_strjoin(tmp, line);
		ft_strdel(&line);
	}
	close(fd);
	return (tmp);
}