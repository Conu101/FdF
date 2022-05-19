/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnov <mrozhnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:45:42 by mrozhnov          #+#    #+#             */
/*   Updated: 2022/05/19 17:00:51 by mrozhnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	exit_msg(int code)
{
	if (!code)
		write(1, "Error\n", 6);
	if (code == 1)
	{
		write(1, "Error: add the 1 argument\n", 27);
	}
	if (code == 2)
		write(1, "Error: uncorrect map\n", 22);
	if (code == 3)
		write(1, "Error: stack_overflow\n", 23);
	if (code == 4)
		write(1, "Error: map was not found\n", 26);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		exit_msg (1);
	map = (t_map *)malloc(sizeof(*map));
	if (!map)
		exit_msg(3);
	parse_map(argv[1], map);
	handle_image(map);
	system("leaks fdf");
	return (0);
}
