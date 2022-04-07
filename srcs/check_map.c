/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:39:23 by gudias            #+#    #+#             */
/*   Updated: 2022/04/07 20:35:06 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	line_is_walls(char *line)
{
	while (*line && *line != '\n')
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}

static void	check_first_line(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		exit_msg("empty map");
	if (!line_is_walls(line))
		exit_msg("first line should be walls only");
	game->map_w = ft_strlen(line) - 1;
	game->map_h = 1;
	game->map = malloc(sizeof(char*));
	if (!game->map)
		exit_msg("malloc");
	game->map[0] = line;
}

static void	check_line_data(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (++i < game->map_w - 1)
	{
		if (line[i] == 'C')
			game->coinleft++;
		else if (line[i] == 'P')
		{
			if (game->player_x != -1)
				exit_msg("more than 1 player");	
			game->player_x = i;
			game->player_y = game->map_h;
			line[i] = '0';
		}
		else if (line[i] == 'E')
		{
			if (game->exit)
				exit_msg("more than 1 exit");
			game->exit = 1;
		}
		else if (line[i] != '0' && line[i] != '1' && line[i] != 'X')
			exit_msg("invalid character in map");
	}	
}

static void	save_line(char *line, t_game *game)
{
	int	i;
	char	**tmp;

	tmp = game->map;
	game->map = malloc(sizeof(char*) * ++(game->map_h));
	if (!game->map)
		exit_msg("malloc");
	i = 0;
	while (i < game->map_h - 1)
	{
		game->map[i] = tmp[i];
		i++;
	}
	free (tmp);
	game->map[i] = line;
}

static char	**read_map(int fd, t_game *game)
{
	char	*line;
	int	len;

	check_first_line(fd, game);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line) - 1;
		if (line[len] != '\n')
			len++;
		if (len != game->map_w)
			exit_msg("map should be rectangle");
		if (line[0] != '1' || line[game->map_w - 1] != '1')
			exit_msg("both sides of the map should be walls");
		check_line_data(line, game);
		save_line(line, game);
		line = get_next_line(fd);
	}
	if (!game->coinleft || game->player_x == -1 || !game->exit)
		exit_msg("map should have at least 1 player, 1 coin and 1 exit");
	if (!line_is_walls(game->map[game->map_h - 1]))
		exit_msg("last line should be walls only");
	return (game->map);
}

char	**readcheck_map(char *mapname, t_game *game)
{
	int	fd;
	char	**map;
	char	*path;
	int	len;
	
	len = ft_strlen(mapname);
	if (ft_strncmp(mapname + (len - 4), ".ber", 4))
		exit_msg("invalid map extension");
	path = ft_pathjoin(MAPSDIR, mapname);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd <= 0)
		exit_msg("couldn't find map in "MAPSDIR);
	map = read_map(fd, game);
	return (map);
}
