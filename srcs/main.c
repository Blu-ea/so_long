/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:31:39 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/29 04:42:21 by amiguez          ###   ########.fr       */
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
	debug(0, game);
	ft_init_xpm(&game);
	printf("test\n");
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.info.x * game.sprites.width,
			game.info.y * game.sprites.height, "so_long");
	ft_render_windows(game, game.sprites.width, game.sprites.height);
	my_hook(&game);
	mlx_loop(game.mlx);
	free(game.info.map);
}
