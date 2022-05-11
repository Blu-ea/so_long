/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pressing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 01:56:01 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/11 06:41:49 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_loop(t_long *game)
{
	ft_render_windows(*game, game->sprit.width, game->sprit.height);
	mlx_hook(game->win, 2, 0, my_hook, game);
	mlx_hook(game->win, 17, 0, k_exit, game);
	mlx_loop(game->mlx);
}

int	my_hook(int key, t_long *game)
{
	if (key == K_D || key == K_RIGHT)
		move_right(game);
	if (key == K_A || key == K_LEFT)
		move_left(game);
	if (key == K_W || key == K_UP)
		move_up(game);
	if (key == K_S || key == K_DOWN)
		move_down(game);
	if (key == K_ESC)
		k_exit(game);
	ft_render_windows(*game, game->sprit.width, game->sprit.height);
	return (0);
}

int	k_exit(t_long *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->sprit.g);
	mlx_destroy_image(game->mlx, game->sprit.w);
	mlx_destroy_image(game->mlx, game->sprit.p);
	mlx_destroy_image(game->mlx, game->sprit.e);
	mlx_destroy_image(game->mlx, game->sprit.c);
	free(game->info.map);
	free(game->mlx);
	exit(0);
}
