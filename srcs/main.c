/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:31:39 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/12 06:55:28 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;

	i = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window (mlx_ptr, 1000, 1000, "so_long");
	mlx_pixel_put(mlx_ptr, win_ptr, 500, 500, 255);
	i++;
	mlx_loop(mlx_ptr);
}
