/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:05:24 by gudias            #+#    #+#             */
/*   Updated: 2022/05/31 00:41:43 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_input(int key, t_game *game)
{
	if (key == K_UP || key == K_DOWN || key == K_LEFT || key == K_RIGHT)
		check_player_move(game, key);
	else if (key == K_ESC)
		close_window(game);
	return (0);
}

int	update_frame(t_game *game)
{
	static int	frame = 0;
	int			player_speed;
	int			open_speed;
	int			enemy_speed;

	if (game->end)
	{
		sleep(3);
		close_game(game);
	}
	player_speed = 1000;
	open_speed = 2000;
	enemy_speed = 1500;
	if (frame >= 99999999)
		frame = 0;
	if (!(frame % player_speed))
		anim_player_idle(game);
	if (game->enemy_x != -1 && !(frame % enemy_speed))
		anim_enemy_idle(game);
	if (game->coinleft == 0 && game->exit < 6 && !(frame % open_speed))
		anim_exit_open(game);
	frame++;
	return (0);
}

int	close_window(t_game *game)
{
	ft_putendl("Closed window");
	close_game(game);
}
