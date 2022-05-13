/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:43:57 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/13 19:18:39 by amiguez          ###   ########.fr       */
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
# include "./sl_key.h" // key define
typedef struct s_map
{
	char	*map;
	int		x;
	int		y;
	char	*name;
}			t_map;

typedef struct s_sprites
{
	void	*g;
	void	*w;
	void	*p;
	void	*e;
	void	*c;
	int		width;
	int		height;
}			t_sprites;

typedef struct s_count
{
	int		e;
	int		c;
	int		p;
}			t_count;

typedef struct s_long
{
	void		*mlx;
	void		*win;
	char		*addr;
	t_map		info;
	t_sprites	sprit;
	t_count		ecp;
	int			move;
}			t_long;

// *************************** //

// *************************** //

//      main.c       //

int		main(int argc, char **argv);
void	ft_error(char *str, void *dump);
void	k_end(t_long *game);
void	ft_p_putnbr_fd(int n, int fd);

//     parsec.c      //

void	ft_parsec(int argc, char **argv, t_long *game);
void	ft_parsec2(t_long *game, int fd, char **argv);
int		ft_has_wall(char *line, int len);
int		ft_content_map(t_long *game);
int		is_full_wall(char *line);

//     render.c      //

void	ft_render_windows(t_long game, int width, int height);
void	ft_init_xpm(t_long *game);
void	ft_choise_tile(t_long game, char tile, int c, int e);
void	mlx_myput_string(t_long game);

//     pressing.c    //

void	my_loop(t_long *game);
int		my_hook(int key, t_long *game);
int		k_exit(t_long *game);

//     move.c        //

void	move_right(t_long *game);
void	move_left(t_long *game);
void	move_up(t_long *game);
void	move_down(t_long *game);

// *************************** //
// ********* debug.c ********* //

void	print_map(t_map info);
void	debug(int index, t_long game);

// *************************** //
#endif