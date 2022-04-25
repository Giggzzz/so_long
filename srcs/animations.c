/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:43:34 by gudias            #+#    #+#             */
/*   Updated: 2022/04/25 01:46:43 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_player(t_game *game)
{
	draw_tile(game, game->player_x, game->player_y);
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

void	change_player_direction(t_game *game)
{
	game->player_dir = -(game->player_dir);
	anim_player(game);
}

void	anim_enemy(t_game *game)
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
