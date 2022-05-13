/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:31:39 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/13 19:31:19 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str, void *dump)
{
	if (dump != NULL)
		free(dump);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_long	game;

	ft_parsec(argc, argv, &game);
	ft_init_xpm(&game);
	game.win = mlx_new_window(game.mlx, game.info.x * game.sprit.width,
			game.info.y * game.sprit.height, "so_long");
	printf("mlx = %p\n", game.mlx);
	my_loop(&game);
}

void	k_end(t_long *game)
{
	int		fd;
	char	*h_sc;
	int		i;

	i = 0;
	while (game->info.name[i] != '.')
	{
		i++;
	}
	game->info.name[i + 1] = 't';
	game->info.name[i + 2] = 'x';
	game->info.name[i + 3] = 't';
	fd = open(game->info.name, O_CREAT | O_RDWR, 0666);
	if (fd == -1)
		k_exit(game);
	h_sc = get_next_line(fd);
	if (ft_atoi(h_sc) > game->move || h_sc == NULL || ft_atoi(h_sc) == 0)
	{
		ft_p_putnbr_fd(game->move, fd);
		ft_printf("New hight score: %d\n", game->move);
	}
	if(h_sc)
		ft_printf("Best score was: %s", h_sc);
	close(fd);
	free(h_sc);
	k_exit(game);
}

void	ft_p_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	str = ft_strjoin_gnl(str, "\n");
	pwrite(fd, str, ft_strlen(str), 0);
	free(str);
}
