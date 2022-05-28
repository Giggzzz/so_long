/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:43:34 by gudias            #+#    #+#             */
/*   Updated: 2022/05/28 02:23:04 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animator(t_game *game)
{
		
}

void	anim_player_idle(t_game *game)
{
	draw_tile(game, game->player_x, game->player_y);
	draw_tile(game, game->player_x+1, game->player_y);
	if (game->player_anim == 0 && game->player_dir == 1)
		game->player_img = PLAYER_RIGHT1;
	else if (game->player_anim == 0)
		game->player_img = PLAYER_LEFT1;
	else if (game->player_anim == 1 && game->player_dir == 1)
		game->player_img = PLAYER_RIGHT2;
	else if (game->player_anim == 1)
		game->player_img = PLAYER_LEFT2;
	else if (game->player_anim == 2 && game->player_dir == 1)
		game->player_img = PLAYER_RIGHT3;
	else if (game->player_anim == 2)
		game->player_img = PLAYER_LEFT3;
	else if (game->player_anim == 3 && game->player_dir == 1)
		game->player_img = PLAYER_RIGHT4;
	else if (game->player_anim == 3)
		game->player_img = PLAYER_LEFT4;
	else if (game->player_anim == 4 && game->player_dir == 1)
		game->player_img = PLAYER_RIGHT5;
	else if (game->player_anim == 4)
		game->player_img = PLAYER_LEFT5;
	draw_player(game);
}

void	anim_enemy_idle(t_game *game)
{
	draw_tile(game, game->enemy_x, game->enemy_y);
	if (game->enemy_anim == 0 && game->enemy_dir == 1)
		game->enemy_img = ENEMY_RIGHT1;
	else if (game->enemy_anim == 0)
		game->enemy_img = ENEMY_LEFT1;
	else if (game->enemy_anim == 1 && game->enemy_dir == 1)
		game->enemy_img = ENEMY_RIGHT2;
	else if (game->enemy_anim == 1)
		game->enemy_img = ENEMY_LEFT2;
	else if (game->enemy_anim == 2 && game->enemy_dir == 1)
		game->enemy_img = ENEMY_RIGHT3;
	else if (game->enemy_anim == 2)
		game->enemy_img = ENEMY_LEFT3;
	else if (game->enemy_anim == 3 && game->enemy_dir == 1)
		game->enemy_img = ENEMY_RIGHT4;
	else if (game->enemy_anim == 3)
		game->enemy_img = ENEMY_LEFT4;
	draw_tile(game, game->enemy_x, game->enemy_y);
}

void	anim_exit_open(t_game *game)
{
	game->exit++;
	if (game->exit == 2)
		game->exit_img = EXIT2;
	else if (game->exit == 3)
		game->exit_img = EXIT3;
	else if (game->exit == 4)
		game->exit_img = EXIT4;
	else if (game->exit == 5)
		game->exit_img = EXIT5;
	else if (game->exit == 6)
		game->exit_img = EXIT6;
	draw_tile(game, game->exit_x, game->exit_y);
}

void	change_player_direction(t_game *game)
{
	game->player_dir = -(game->player_dir);
	anim_player_idle(game);
}
