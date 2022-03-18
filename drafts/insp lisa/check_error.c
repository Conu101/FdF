/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:13:25 by ctrouve           #+#    #+#             */
/*   Updated: 2022/03/18 11:13:49 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	check_error(char *str)
{
	int		i;
	int		m;

	i = 0;
	while (str[i] != '\0')
	{
		m = 0;
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] != ' ')
				m = m + 1;
			if (str[i] != '-')
				m = m + 1;
			if (m == 2)
			{
				ft_putstr("Map error\n");
				free(str);
				exit(0);
			}
		}
		i++;
	}
}
