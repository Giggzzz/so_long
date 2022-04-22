/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:19:38 by gudias            #+#    #+#             */
/*   Updated: 2022/04/22 23:30:27 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_map(char *mapname)
{
	int		fd;
	char	*path;

	path = ft_pathjoin(MAPSDIR, mapname);
	fd = open(path, O_RDONLY);
	free(path);
	return (fd);
}

static void	get_first_line(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		exit_msg(game, "map is empty");
	if (!check_walls(line))
		exit_msg(game, "first line should be walls only");
	game->map_w = ft_strlen(line) - 1;
	game->map_h = 1;
	game->map = malloc(sizeof (char *) * 2);
	if (!game->map)
		exit_msg(game, "malloc");
	game->map[0] = line;
	game->map[1] = NULL;
}

void	get_line_data(char *line, int i, t_game *game)
{
	if (line[i] == 'C')
		game->coinleft++;
	else if (line[i] == 'P')
	{
		game->player_x = i;
		game->player_y = game->map_h;
		line[i] = '0';
	}
	else if (line[i] == 'E')
		game->exit = 1;
	else if (line[i] == 'X')
	{
		game->enemy_x = i;
		game->enemy_y = game->map_h;
	}
}

static void	save_line(char *line, t_game *game)
{
	int		i;
	char	**tmp;

	tmp = game->map;
	game->map = malloc(sizeof (char *) * (++(game->map_h) + 1));
	if (!game->map)
		exit_msg(game, "malloc");
	i = 0;
	while (i < game->map_h - 1)
	{
		game->map[i] = tmp[i];
		i++;
	}
	free(tmp);
	game->map[i] = line;
	game->map[i + 1] = NULL;
}

char	**get_map(char *mapname, t_game *game)
{
	int		fd;
	char	*line;

	if (check_extension(mapname))
		exit_msg(game, "invalid map extension, should be .ber");
	fd = open_map(mapname);
	if (fd <= 0)
		exit_msg(game, "cound't find map in "MAPSDIR);
	get_first_line(fd, game);
	line = get_next_line(fd);
	while (line)
	{
		check_line(line, game);
		save_line(line, game);
		line = get_next_line(fd);
	}
	check_map_is_valid(game);
	return (game->map);
}
