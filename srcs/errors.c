/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:39:36 by gudias            #+#    #+#             */
/*   Updated: 2022/04/22 20:03:09 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_msg(t_game *game, char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	close_game(game);
}

void	exit_win(t_game *game)
{	
	int	x;
	int	y;

	x = game->map_w * TILESIZE / 2;
	y = game->map_h * TILESIZE / 2;
	ft_putendl("YOU WIN !");
	mlx_string_put(game->mlx, game->win, x, y, 0x00FF00, "YOU WIN!");
	game->end = 1;
}

void	exit_loose(t_game *game)
{
	int	x;
	int	y;

	x = game->map_w * TILESIZE / 2;
	y = game->map_h * TILESIZE / 2;
	ft_putendl("YOU GOT KILLED! GAME OVER...");
	mlx_string_put(game->mlx, game->win, x, y, 0xFF0000, "GAME OVER!");
	game->end = 1;
}

static void	free_map(char **map)
{
	char	**ptr;

	ptr = map;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(map);
}

void	close_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit (0);
}
