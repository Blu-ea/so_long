/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:28:07 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 15:04:34 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//open a return a malloc char ** of the map
void	ft_parsec(int argc, char **argv, t_long *game)
{
	int		fd;
	char	*line;
	int		i;
	int		full_wall;

	full_wall = 0;
	i = 0;
	if (argc != 2)
		ft_error("usage: ./so_long map_file\n", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("error: map file not found", NULL);
	line = get_next_line(fd);
	printf("result = \"%s\"\n", line);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			ft_error("error: map file not valid 1(no wall on the top)", line);
		i++;
	}
	game -> info_map.size_x = i;
	game -> info_map.map = ft_strdup(line);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_has_wall(line,game -> info_map.size_x) == 1)
			ft_error("error: map file not valid (not close or dif len)", line);
		game -> info_map.map = ft_str_malloc_join(&game -> info_map.map, &line);
		line = get_next_line(fd);
		game -> info_map.size_y++;
	}
	if (full_wall == 1)
		ft_error("error: map file not valid (No wall on the bottom)", NULL);
	close(fd);
}

int	ft_has_wall(char *line, int len)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (1);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'P' && line[i] != 'E')
			return (1);
		i++;
	}
	if (line[i - 1] != '1')
		return (1);
	if (ft_strlen(line) != len)
		return (1);
	return (0);
}
