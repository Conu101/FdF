/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:03:49 by ctrouve           #+#    #+#             */
/*   Updated: 2022/04/11 21:58:41 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 16
# define FD_SIZE 10240
/* check current limit : 
** launchctl limit maxfiles
** To modify the file descriptors limit :
** sudo launchctl limit maxfiles 10240 unlimited
*/

int	get_next_line(const int fd, char **line);

#endif
