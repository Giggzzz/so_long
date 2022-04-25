/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:48:31 by gudias            #+#    #+#             */
/*   Updated: 2022/04/25 02:01:25 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game_vars(t_game *game, char *mapname)
{	
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->player_img = PLAYER_RIGHT1;
	game->player_dir = 1;
	game->player_anim = 0;
	game->enemy_img = PLAYER_RIGHT1;
	game->enemy_dir = -1;
	game->enemy_anim = 0;
	game->player_x = -1;
	game->enemy_x = -1;
	game->exit = 0;
	game->coinleft = 0;
	game->movecount = 0;
	game->end = 0;
	game->map = get_map(mapname, game);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_msg(game, "couldn't init mlx");
	game->win = mlx_new_window(game->mlx, game->map_w * TILESIZE,
			game->map_h * TILESIZE, "42 | so_long");
	if (!game->win)
		exit_msg(game, "couldn't create window");
}

static void	init_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_input, game);
	mlx_hook(game->win, 17, 0L << 0, close_window, game);
	mlx_loop_hook(game->mlx, update_frame, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putendl("Error\ninvalid arguments");
		return (0);
	}
	init_game_vars(&game, argv[1]);
	draw_map(&game);
	init_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
