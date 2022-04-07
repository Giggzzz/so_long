/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:54:11 by gudias            #+#    #+#             */
/*   Updated: 2022/04/07 19:11:15 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_ennemy(t_game *game)
{
	int	dx;
	int	dy;

}

void	move_player(t_game *game, int key)
{
	draw_tile(game, game->player_x, game->player_y);
	if (key == UP)
		game->player_y--;
	else if (key == DOWN)
		game->player_y++;
	else if (key == LEFT)
		game->player_x--;
	else if (key == RIGHT)
		game->player_x++;
	draw_player(game);
	game->movecount++;
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
	refresh_score(game);
}
