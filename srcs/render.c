/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:40:03 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/11 05:45:35 by amiguez          ###   ########.fr       */
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
			mlx_put_image_to_window(game.mlx, game.win, game.sprit.w,
				count.c * width, count.e * height);
		else if (game.info.map[count.p] == '0')
			mlx_put_image_to_window(game.mlx, game.win, game.sprit.g,
				count.c * width, count.e * height);
		else if (game.info.map[count.p] == 'C')
			mlx_put_image_to_window(game.mlx, game.win, game.sprit.c,
				count.c * width, count.e * height);
		else if (game.info.map[count.p] == 'P')
			mlx_put_image_to_window(game.mlx, game.win, game.sprit.p,
				count.c * width, count.e * height);
		else if (game.info.map[count.p] == 'E')
			mlx_put_image_to_window(game.mlx, game.win, game.sprit.e,
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
	game->sprit.w = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall.XPM",
			&game->sprit.width, &game->sprit.height);
	game->sprit.g = mlx_xpm_file_to_image(game->mlx,
			"sprites/ground.xpm",
			&game->sprit.width, &game->sprit.height);
	game->sprit.c = mlx_xpm_file_to_image(game->mlx,
			"sprites/colectible.xpm",
			&game->sprit.width, &game->sprit.height);
	game->sprit.p = mlx_xpm_file_to_image(game->mlx,
			"sprites/character.xpm",
			&game->sprit.width, &game->sprit.height);
	game->sprit.e = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit.xpm",
			&game->sprit.width, &game->sprit.height);
	if (game->sprit.w == NULL || game->sprit.g == NULL ||
		game->sprit.c == NULL || game->sprit.p == NULL || game->sprit.e == NULL)
		ft_error("Error:sprite not found\n", game->mlx);
}
