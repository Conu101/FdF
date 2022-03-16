/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:56:59 by ctrouve           #+#    #+#             */
/*   Updated: 2022/03/16 12:59:58 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

/*
** it takes 3 bytes to define a color with 16'777'216 shades.
**
** 0x  FF FF FF
** Hex RR GG BB
** 
** A color can be made by mixing Red, Green and Blue, so it is called the 
** "RGB Color System".
** It is also called an "Additive" color system, because it starts at black, 
** and then color is added.
** https://www.mathsisfun.com/hexadecimal-decimal-colors.html
*/

int	rgb_to_int(double r, double g, double b)
{
	int color = 0;

	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}
