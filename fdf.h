/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:13:53 by ctrouve           #+#    #+#             */
/*   Updated: 2022/03/16 13:59:56 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>

int	rgb_to_int(double r, double g, double b);

int	draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);


# endif
