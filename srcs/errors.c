/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:39:36 by gudias            #+#    #+#             */
/*   Updated: 2022/04/04 18:32:06 by gudias           ###   ########.fr       */
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

void	exit_win(t_vars *vars)
{
	ft_printf("YOU WIN !\nIt tooks you %d moves..\n", vars->movecount);
	
	mlx_string_put(vars->mlx, vars->win, (vars->map_w)*25, (vars->map_h)*25, 0x00FF00, "YOU WIN!");
	//exit (0);
}

void	exit_loose(t_vars *vars)
{
	ft_putendl("YOU GOT KILLED! GAME OVER...\n");
	mlx_string_put(vars->mlx, vars->win, (vars->map_w)*25, (vars->map_h)*25, 0xFF0000, "GAME OVER!");
	//exit (0);
}

//should free all before exit..
