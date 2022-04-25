/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:43:57 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 12:23:09 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h" // libft
# include "minilibx_opengl_20191021/mlx.h" // mlx
# include <math.h> // al math fonction
# include <stdio.h> // perror and strerror
# include <stdlib.h> // exit , malloc , free
# include <fcntl.h> // open , close
# include <unistd.h> // write , read

typedef struct s_map
{
	char	*map;
	int		size_x;
	int		size_y;
}			t_map;

typedef struct s_long
{
	void	*ptr_mlx;
	void	*ptr_win;
	t_map	info_map;
}			t_long;

// *************************** //

//      main.c       //

int		main(int argc, char **argv);
void	ft_error(char *str, void *dump);

//     parsec.c      //

void	ft_parsec(int argc, char **argv, t_long *game);
int		ft_has_wall(char *line);

// *************************** //
// ********* debug.c ********* //

void	print_map(t_map info);
void	debug(int index, t_long game);

// *************************** //
#endif