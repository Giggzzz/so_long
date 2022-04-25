/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:54:11 by gudias            #+#    #+#             */
/*   Updated: 2022/04/25 01:52:01 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_next_tile(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->coinleft--;
	}
	else if (game->map[game->player_y][game->player_x] == 'E' && \
			game->coinleft == 0)
		exit_win(game);
	else if (game->map[game->player_y][game->player_x] == 'X')
		exit_loose(game);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	draw_tile(game, game->player_x, game->player_y);
	game->player_x = new_x;
	game->player_y = new_y;
	draw_player(game);
	game->movecount++;
	check_next_tile(game);
	refresh_score(game);
	if (game->enemy_x != -1 && !(game->movecount % 2))
		move_enemy(game);
}

void	check_player_move(t_game *game, int key)
{
	int	new_x;
	int	new_y;

	if (game->end)
		return ;
	new_x = game->player_x;
	new_y = game->player_y;
	if (key == K_UP)
		new_y--;
	else if (key == K_DOWN)
		new_y++;
	else if (key == K_LEFT)
		new_x--;
	else if (key == K_RIGHT)
		new_x++;
	if (key == K_RIGHT && game->player_dir == -1 \
			|| key == K_LEFT && game->player_dir == 1)
		change_player_direction(game);
	if (game->map[new_y][new_x] != '1')
		move_player(game, new_x, new_y);
}
