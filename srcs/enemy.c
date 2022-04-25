/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:43:33 by gudias            #+#    #+#             */
/*   Updated: 2022/04/25 02:05:43 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

static void	calc_enemy_move(t_game *game)
{	
	int	dx;
	int	dy;
	int	x;
	int	y;

	game->enemy_dir = 1;
	x = 1;
	y = 1;
	dx = game->player_x - game->enemy_x;
	dy = game->player_y - game->enemy_y;
	if (dx < 0)
	{
		x = -1;
		game->enemy_dir = -1;
	}
	if (dy < 0)
		y = -1;
	if (ft_abs(dx) > ft_abs(dy) \
			&& game->map[game->enemy_y][game->enemy_x + x] == '0')
		game->enemy_x += x;
	else if (game->map[game->enemy_y + y][game->enemy_x] == '0')
		game->enemy_y += y;
	else if (game->map[game->enemy_y][game->enemy_x + x] == '0')
		game->enemy_x += x;
}

void	move_enemy(t_game *game)
{
	game->map[game->enemy_y][game->enemy_x] = '0';
	draw_tile(game, game->enemy_x, game->enemy_y);
	calc_enemy_move(game);
	game->map[game->enemy_y][game->enemy_x] = 'X';
	draw_tile(game, game->enemy_x, game->enemy_y);
	if (game->enemy_x == game->player_x && game->enemy_y == game->player_y)
		exit_loose(game);
}
