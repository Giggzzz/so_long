/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:54:11 by gudias            #+#    #+#             */
/*   Updated: 2022/04/11 14:13:58 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_abs(int	val)
{
	if (val < 0)
		return (-val);
	return (val);
}

void	move_ennemy(t_game *game)
{
	int	dx;
	int	dy;
	int	x;
	int	y;

	x = 1;
	y = 1;
	dx = game->player_x - game->enemy_x;
	dy = game->player_y - game->enemy_y;
	if (dx < 0)
		x = -1;
	if (dy < 0)
		y = -1;
	game->map[game->enemy_y][game->enemy_x] = '0';
	draw_tile(game, game->enemy_x, game->enemy_y);
	if (ft_abs(dx) > ft_abs(dy) && game->map[game->enemy_y][game->enemy_x + x] == '0')
		game->enemy_x += x;
	else if (game->map[game->enemy_y + y][game->enemy_x] == '0')
		game->enemy_y += y;
	else  if (game->map[game->enemy_y][game->enemy_x + x] == '0')
		game->enemy_x += x;
	game->map[game->enemy_y][game->enemy_x] = 'X';
	draw_tile(game, game->enemy_x, game->enemy_y);
	if (game->enemy_x == game->player_x && game->enemy_y == game->player_y)
		exit_loose(game);
}

void	move_player(t_game *game, int key)
{
	draw_tile(game, game->player_x, game->player_y);
	if (key == K_UP)
		game->player_y--;
	else if (key == K_DOWN)
		game->player_y++;
	else if (key == K_LEFT)
		game->player_x--;
	else if (key == K_RIGHT)
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
	if (game->enemy_x != -1 && !(game->movecount % 2))
		move_ennemy(game);
}
