/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:31:39 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/11 05:22:32 by amiguez          ###   ########.fr       */
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
