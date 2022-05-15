/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:31:39 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/15 11:17:35 by amiguez          ###   ########.fr       */
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
	my_loop(&game);
}

void	k_end(t_long *game)
{
	char	*h_sc;
	t_count	i;

	i.c = 0;
	while (game->info.name[i.c] != '.')
	{
		i.c++;
	}
	game->info.name[i.c + 1] = 't';
	game->info.name[i.c + 2] = 'x';
	game->info.name[i.c + 3] = 't';
	i.e = open(game->info.name, O_CREAT | O_RDWR, 0666);
	if (i.e == -1)
		k_exit(game);
	h_sc = get_next_line(i.e);
	if (ft_atoi(h_sc) > game->move || h_sc == NULL || ft_atoi(h_sc) == 0)
	{
		ft_p_putnbr_fd(game->move, i.e);
		ft_printf("New hight score: %d\n", game->move);
	}
	if (h_sc)
		ft_printf("Best score was: %d", ft_atoi(h_sc));
	close(i.e);
	free(h_sc);
	k_exit(game);
}

void	ft_p_putnbr_fd(int n, int fd)
{
	char	*str;
	int		i;
	char	*temp;

	str = ft_itoa(n);
	i = 12 - ft_strlen(str);
	while (i)
	{
		temp = ft_strjoin("0", str);
		free(str);
		str = temp;
		i--;
	}
	pwrite(fd, str, ft_strlen(str), 0);
	free(str);
}
