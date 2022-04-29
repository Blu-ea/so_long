/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:40:03 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/29 04:46:59 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_render_windows(t_long game, int width, int height)
{
	t_count		count;

	count.e = 0;
	count.c = 0;
	count.p = -1;
	while (game.info.map[++count.p])
	{
		if (game.info.map[count.p] == '1')
			mlx_put_image_to_window(game.mlx, game.win, game.sprites.w,
				count.c * width, count.e * height);
		else if (game.info.map[count.p] == '0')
			mlx_put_image_to_window(game.mlx, game.win, game.sprites.g,
				count.c * width, count.e * height);
		else if (game.info.map[count.p] == 'C')
			mlx_put_image_to_window(game.mlx, game.win, game.sprites.c,
				count.c * width, count.e * height);
		else if (game.info.map[count.p] == 'P')
			mlx_put_image_to_window(game.mlx, game.win, game.sprites.p,
				count.c * width, count.e * height);
		else if (game.info.map[count.p] == 'E')
			mlx_put_image_to_window(game.mlx, game.win, game.sprites.e,
				count.c * width, count.e * height);
		else if (game.info.map[count.p] == '\n' )
		{
			count.c = -1;
			count.e++;
		}
		count.c++;
	}
}

void	ft_init_xpm(t_long *game)
{
	game->sprites.w = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall.xpm",
			&game->sprites.width, &game->sprites.height);
	game->sprites.g = mlx_xpm_file_to_image(game->mlx,
			"./sprites/ground.xpm",
			&game->sprites.width, &game->sprites.height);
	game->sprites.c = mlx_xpm_file_to_image(game->mlx,
			"./sprites/colectible.xpm",
			&game->sprites.width, &game->sprites.height);
	game->sprites.p = mlx_xpm_file_to_image(game->mlx,
			"./sprites/character.xpm",
			&game->sprites.width, &game->sprites.height);
	game->sprites.e = mlx_xpm_file_to_image(game->mlx,
			"./sprites/exit.xpm",
			&game->sprites.width, &game->sprites.height);
}
