/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 05:46:17 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/13 19:39:42 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_long *game)
{
	int	i;

	i = 0;
	while (game->info.map[i] != 'P')
		i++;
	if (game->info.map[i + 1] == '1')
		write (1, "There is a wall\n", 16);
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
		ft_printf("moves: %d\n", ++game->move);
		k_end(game);
	}
}

void	move_left(t_long *game)
{
	int	i;

	i = 0;
	while (game->info.map[i] != 'P')
		i++;
	if (game->info.map[i - 1] == '1')
		write (1, "There is a wall\n", 16);
	else if (game->info.map[i - 1] == 'C' || game->info.map[i - 1] == '0')
	{
		if (game->info.map[i - 1] == 'C')
			game->ecp.c--;
		game->info.map[i] = '0';
		game->info.map[i - 1] = 'P';
		ft_printf("moves: %d\n", ++game->move);
	}
	else if (game->info.map[i - 1] == 'E' && game->ecp.c != 0)
		write(1, "There is still some colectibles to get\n", 40);
	else if (game->info.map[i - 1] == 'E' && game->ecp.c == 0)
	{
		ft_printf("moves: %d\n", ++game->move);
		k_end(game);
	}
}

void	move_up(t_long *game)
{
	int	i;

	i = 0;
	while (game->info.map[i] != 'P')
		i++;
	if (game->info.map[i - game->info.x - 1] == '1')
		write (1, "There is a wall\n", 16);
	else if (game->info.map[i - game->info.x - 1] == 'C'
		|| game->info.map[i - game->info.x - 1] == '0')
	{
		if (game->info.map[i - game->info.x - 1] == 'C')
			game->ecp.c--;
		game->info.map[i] = '0';
		game->info.map[i - game->info.x - 1] = 'P';
		ft_printf("moves: %d\n", ++game->move);
	}
	else if (game->info.map[i - game->info.x - 1] == 'E' && game->ecp.c != 0)
		write(1, "There is still some colectibles to get\n", 40);
	else if (game->info.map[i - game->info.x - 1] == 'E' && game->ecp.c == 0)
	{
		ft_printf("moves: %d\n", ++game->move);
		k_end(game);
	}
}

void	move_down(t_long *game)
{
	int	i;

	i = 0;
	while (game->info.map[i] != 'P')
		i++;
	if (game->info.map[i + game->info.x + 1] == '1')
		write (1, "There is a wall\n", 16);
	else if (game->info.map[i + game->info.x + 1] == 'C'
		|| game->info.map[i + game->info.x + 1] == '0')
	{
		if (game->info.map[i + game->info.x + 1] == 'C')
			game->ecp.c--;
		game->info.map[i] = '0';
		game->info.map[i + game->info.x + 1] = 'P';
		ft_printf("moves: %d\n", ++game->move);
	}
	else if (game->info.map[i + game->info.x + 1] == 'E' && game->ecp.c != 0)
		write(1, "There is still some colectibles to get\n", 40);
	else if (game->info.map[i + game->info.x + 1] == 'E' && game->ecp.c == 0)
	{
		ft_printf("moves: %d\n", ++game->move);
		k_end(game);
	}
}
