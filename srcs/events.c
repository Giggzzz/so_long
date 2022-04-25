/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:05:24 by gudias            #+#    #+#             */
/*   Updated: 2022/04/25 02:23:04 by gudias           ###   ########.fr       */
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
	int			freq;

	if (game->end)
	{
		sleep(3);
		close_game(game);
	}
	freq = 1000;
	if (frame == freq * 5)
		frame = 0;
	if (!(frame % freq))
	{
		game->player_anim = frame / freq;
		anim_player(game);
		if (game->enemy_x != -1)
		{
			game->enemy_anim = frame / freq;
			anim_enemy(game);
		}
	}
	frame++;
	return (0);
}

int	close_window(t_game *game)
{
	ft_putendl("Closed window");
	close_game(game);
}
