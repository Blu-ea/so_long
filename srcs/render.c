/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:40:03 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/13 19:40:34 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_render_windows(t_long game, int width, int height)
{
	t_count		i;

	i.e = 0;
	i.c = 0;
	i.p = -1;
	while (game.info.map[++i.p])
	{
		if (game.info.map[i.p] == '1')
			ft_choise_tile(game, '1', i.c, i.e);
		else if (game.info.map[i.p] == '0')
			ft_choise_tile(game, '0', i.c, i.e);
		else if (game.info.map[i.p] == 'C')
			ft_choise_tile(game, 'C', i.c, i.e);
		else if (game.info.map[i.p] == 'P')
			ft_choise_tile(game, 'P', i.c, i.e);
		else if (game.info.map[i.p] == 'E')
			ft_choise_tile(game, 'E', i.c, i.e);
		else if (game.info.map[i.p] == '\n' )
		{
			i.c = -1;
			i.e++;
		}
		i.c++;
	}
}

void	ft_choise_tile(t_long game, char tile, int c, int e)
{
	if (tile == '1')
		mlx_put_image_to_window(game.mlx, game.win, game.sprit.w,
			c * game.sprit.width, e * game.sprit.height);
	else if (tile == '0')
		mlx_put_image_to_window(game.mlx, game.win, game.sprit.g,
			c * game.sprit.width, e * game.sprit.height);
	else if (tile == 'C')
		mlx_put_image_to_window(game.mlx, game.win, game.sprit.c,
			c * game.sprit.width, e * game.sprit.height);
	else if (tile == 'P')
		mlx_put_image_to_window(game.mlx, game.win, game.sprit.p,
			c * game.sprit.width, e * game.sprit.height);
	else if (tile == 'E')
		mlx_put_image_to_window(game.mlx, game.win, game.sprit.e,
			c * game.sprit.width, e * game.sprit.height);
	mlx_myput_string(game);
}

void	mlx_myput_string(t_long game)
{
	char	*str;
	char	*move;

	str = ft_strdup(" Move=");
	move = ft_itoa(game.move);
	str = ft_str_malloc_join(&str, &move);
	mlx_string_put(game.mlx, game.win, 5, game.sprit.height * game.info.y,
		0xFFFFFF, str);
	free (str);
	mlx_string_put(game.mlx, game.win, 10, 10, 0xFFFFFF, "Press esc to quit");
	str = ft_strdup(" Score=");
	move = ft_itoa(game.ecp.c);
	str = ft_str_malloc_join(&str, &move);
	mlx_string_put(game.mlx, game.win, 5, game.sprit.height * game.info.y - 15,
		0xFFFFFF, str);
	free (str);
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
	if (game->sprit.w == NULL || game->sprit.g == NULL
		|| game->sprit.c == NULL || game->sprit.p == NULL
		|| game->sprit.e == NULL)
		ft_error("Error:sprite not found\n", game->mlx);
}
