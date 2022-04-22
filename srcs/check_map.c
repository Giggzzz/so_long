/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:39:23 by gudias            #+#    #+#             */
/*   Updated: 2022/04/22 19:14:48 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *mapname)
{
	int	len;

	len = ft_strlen(mapname);
	if (ft_strncmp(mapname + (len - 4), ".ber", 4))
		return (1);
	return (0);
}

int	check_walls(char *line)
{
	while (*line && *line != '\n')
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}

static int	check_charset(char c)
{
	if (c == '0' || c == '1' || c == 'C')
		return (1);
	else if (c == 'P' || c == 'E' || c == 'X')
		return (1);
	return (0);
}

void	check_line(char *line, t_game *game)
{
	int	len;
	int	i;

	len = ft_strlen(line) - 1;
	if (line[len] != '\n')
		len++;
	if (len != game->map_w)
		exit_msg(game, "map should be rectangle");
	if (line[0] != '1' || line[len - 1] != '1')
		exit_msg(game, "both sides of the map should be walls");
	i = 0;
	while (++i < game->map_w - 1)
	{
		if (line[i] == 'P' && game->player_x != -1)
			exit_msg(game, "more than 1 player");
		else if (line[i] == 'E' && game->exit)
			exit_msg(game, "more than 1 exit");
		else if (line[i] == 'X' && game->enemy_x != -1)
			exit_msg(game, "only 1 enemy atm :/");
		else if (!check_charset(line[i]))
			exit_msg(game, "invalid character in map");
	}
}

void	check_map_is_valid(t_game *game)
{
	if (!game->coinleft || game->player_x == -1 || !game->exit)
		exit_msg(game, "map should have at least 1 player, 1 coin and 1 exit");
	if (!check_walls(game->map[game->map_h - 1]))
		exit_msg(game, "last line should be walls only");
}
