/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:40:03 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/27 18:05:51 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_render_windows(t_long game)
{
	void	*img_ptr;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.info.x * 32,
			game.info.y * 32, "so_long");
	img_ptr = mlx_xpm_file_to_image(game.mlx, "sprites/ground.xpm",
			&x, &y);
	x = 0;
	y = 0;
	while (game.info.map[i])
	{
		if (game.info.map[i] == '1')
		{
			mlx_put_image_to_window(game.mlx, game.win, img_ptr,
				x * 32, y * 32);
			x++;
		}
		else if (game.info.map[i] == '\n' )
		{
			x = 0;
			y++;
		}
		else
			x++;
		i++;
	}
	// mlx_destroy_window(game.mlx, game.win);
	// mlx_destroy_image(game.mlx, img_ptr);
	// free(game.mlx);
	mlx_loop(game.mlx);
}
