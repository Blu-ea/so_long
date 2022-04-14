/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:28:07 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/14 13:48:01 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//open a return a malloc char ** of the map
void	ft_parsec(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	printf ("%d\n", fd);
	read(fd, line, 5);
	printf ("%s\n", line);
	// free(line);
	// close(fd);
	// fd = open(argv[1], O_RDONLY);
	// printf ("%d\n", fd);
	// line = get_next_line(fd);
	// printf ("%s\n", get_next_line(fd));
	// free(line);
	close(fd);
}
