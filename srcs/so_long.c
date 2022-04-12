/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:48:31 by gudias            #+#    #+#             */
/*   Updated: 2022/04/11 18:00:11 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game_vars(t_game *game)
{	
	game->player_x = -1;
	game->enemy_x = -1;
	game->exit = 0;
	game->coinleft = 0;
	game->movecount = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_msg("bad arguments");
	init_game_vars(&game);
	game.map = readcheck_map(argv[1], &game);
	game.mlx = mlx_init();
	if (!game.mlx)
		exit_msg("couldn't init mlx");
	game.win = mlx_new_window(game.mlx, \
		game.map_w*TILESIZE, game.map_h*TILESIZE, "42 | so_long");
	if (!game.win)
		exit_msg("couldn't create window");
	draw_map(&game);
	//mlx_key_hook(game.win, key_input, &game);
	mlx_hook(game.win, 2, 0, key_input, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, update_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
