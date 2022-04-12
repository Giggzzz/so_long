/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:39:36 by gudias            #+#    #+#             */
/*   Updated: 2022/04/11 17:09:59 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_msg(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	//free
	exit (0);
}

void	exit_win(t_game *game)
{
	ft_printf("YOU WIN !\nIt tooks you %d moves..\n", game->movecount);
	mlx_clear_window(game->mlx, game->win);
	mlx_string_put(game->mlx, game->win, (game->map_w)*TILESIZE/2, (game->map_h)*TILESIZE/2, 0x00FF00, "YOU WIN!");
	//sleep(5);
	//exit (0);
}

void	exit_loose(t_game *game)
{
	ft_putendl("YOU GOT KILLED! GAME OVER...\n");
	mlx_clear_window(game->mlx, game->win);
	mlx_string_put(game->mlx, game->win, (game->map_w)*TILESIZE/2, (game->map_h)*TILESIZE/2, 0xFF0000, "GAME OVER!");
	//sleep(5);
	//exit (0);
}

static void	free_map(char **map)
{
	char **ptr;

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
	//mlx_destroy_image(mlx, img);
	
	free_map(game->map);

	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}
//should free all before exit..


