/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:05:24 by gudias            #+#    #+#             */
/*   Updated: 2022/04/07 19:11:01 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_move(t_game *game, int newpos_x, int newpos_y)
{
	if (game->map[newpos_y][newpos_x] == '1')
		return (0);
	return (1);
}

int	key_input(int keycode, t_game *game)
{
	//if (keycode == UP && \
	game->map[game->player_y - 1][game->player_x] != '1')
	if (keycode == UP && \
	valid_move(game, game->player_x, game->player_y - 1))
		move_player(game, keycode);
	else if (keycode == DOWN && \
	valid_move(game, game->player_x, game->player_y + 1))
		move_player(game, keycode);
	else if (keycode == LEFT && \
	valid_move(game, game->player_x - 1, game->player_y))
		move_player(game, keycode);
	else if (keycode == RIGHT && \
	valid_move(game, game->player_x + 1, game->player_y))
		move_player(game, keycode);
	else if (keycode == ESCAPE)
		close_window(game);
	else
		ft_printf("bad input: %d\n", keycode);
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_putendl("Closed window");
	exit (0);
}
