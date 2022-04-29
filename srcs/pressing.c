/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pressing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 01:56:01 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/29 04:49:57 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_hook(t_long *game)
{
	mlx_hook(game->win, 2, 0, k_hooks, game);
	// mlx_hook(game->win, 17, 0, k_exit, game);
}

int	k_hooks(int key, t_long *game)
{
	printf("key: %d\n", key);
	if (key == K_D || key == K_RIGHT)
		move_right(game);
// 	if (key == K_A || key == K_LEFT)
// 		move_left(game);
// 	if (key == K_W || key == K_UP)
// 		move_up(game);
// 	if (key == K_S || key == K_DOWN)
// 		move_down(game);
	ft_render_windows(*game, game->sprites.width, game->sprites.height);
	return (0);
}

void	move_right(t_long *game)
{
	int	i;

	i = 0;
	while (game->info.map[i] != 'P')
		i++;
	if (game->info.map[i + 1] == '1')
		write (1, "There is a wall\n", 15);
	else if (game->info.map[i + 1] == 'C' || game->info.map[i + 1] == '0')
	{
		if (game->info.map[i + 1] == 'C')
			game->ecp.c--;
		game->info.map[i] = '0';
		game->info.map[i + 1] = 'P';
		ft_printf("moves: %d\n", ++game->move);
	}
	else if (game->info.map[i + 1] == 'E' && game->ecp.c != 0)
		write(1, "There is still some colectibles to get\n", 40);
	else if (game->info.map[i + 1] == 'E' && game->ecp.c == 0)
	{
		k_exit(game);
		ft_printf("moves: %d\n", ++game->move);
	}
	debug(0, *game);
}

int	k_exit(t_long *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->sprites.g);
	mlx_destroy_image(game->mlx, game->sprites.w);
	mlx_destroy_image(game->mlx, game->sprites.p);
	mlx_destroy_image(game->mlx, game->sprites.e);
	mlx_destroy_image(game->mlx, game->sprites.c);
	free(game->info.map);
	free(game->mlx);
	exit(0);
}
