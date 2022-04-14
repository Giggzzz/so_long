/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:05:24 by gudias            #+#    #+#             */
/*   Updated: 2022/04/14 18:25:20 by gudias           ###   ########.fr       */
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
	//if (keycode == K_UP && \
	game->map[game->player_y - 1][game->player_x] != '1')
	if (keycode == K_UP && \
	valid_move(game, game->player_x, game->player_y - 1))
		move_player(game, keycode);
	else if (keycode == K_DOWN && \
	valid_move(game, game->player_x, game->player_y + 1))
		move_player(game, keycode);
	else if (keycode == K_LEFT && \
	valid_move(game, game->player_x - 1, game->player_y))
		move_player(game, keycode);
	else if (keycode == K_RIGHT && \
	valid_move(game, game->player_x + 1, game->player_y))
		move_player(game, keycode);
	else if (keycode == K_ESC)
		close_window(game);
	else
		ft_printf("bad input: %d\n", keycode);
	return (0);
}

int	update_frame(t_game *game)
{
	static int	frame = 0;
	int		freq = 5000;

	if (frame == freq)
		frame = 0;
	if (frame == 0)
		ft_printf("tick\n");
	frame++;
	mlx_pixel_put(game->mlx, game->win, 100, 100, frame);
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_putendl("Closed window");
	exit (0);
}
