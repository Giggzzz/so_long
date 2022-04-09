/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:39:36 by gudias            #+#    #+#             */
/*   Updated: 2022/04/09 03:37:40 by gudias           ###   ########.fr       */
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
	mlx_string_put(game->mlx, game->win, (game->map_w)*25, (game->map_h)*25, 0x00FF00, "YOU WIN!");
	//sleep(10);
	//exit (0);
}

void	exit_loose(t_game *game)
{
	ft_putendl("YOU GOT KILLED! GAME OVER...\n");
	mlx_string_put(game->mlx, game->win, (game->map_w)*25, (game->map_h)*25, 0xFF0000, "GAME OVER!");	
	//sleep(10);
	//exit (0);
}

//should free all before exit..


	//mlx_destroy_image(mlx, img);
	//mlx_clear_window(mlx, window);
	//mlx_destroy_window(mlx, window);
