/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:15:48 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 14:56:19 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(t_map info)
{
	ft_putstr_fd(info.map, 1);
	write(1, "\n", 1);
}

//index = 0 -> print the map
//index = 1 -> printf a test for segfault
void	debug(int index, t_long game)
{
	if (index == 0)
		print_map(game.info_map);
	if (index == 1)
		printf("test Je suis ici \n");
	if (index == 2)
		printf("je suis un autre test \n");	
}
