/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:05:24 by gudias            #+#    #+#             */
/*   Updated: 2022/04/06 16:40:31 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_is_valid(t_vars *vars, int newpos_x, int newpos_y)
{
	if (vars->map[newpos_y][newpos_x] == '1')
		return (0);
	return (1);
}

int	key_input(int keycode, t_vars *vars)
{
	//if (keycode == UP && vars->player_pos_y>1 && \
			vars->map[vars->player_pos_y - 1][vars->player_pos_x] != '1')
	if (keycode == UP && move_is_valid(vars, vars->player_pos_x, vars->player_pos_y - 1))
		move_player(vars, keycode);
	else if (keycode == DOWN && move_is_valid(vars, vars->player_pos_x, vars->player_pos_y + 1))
		move_player(vars, keycode);
	else if (keycode == LEFT && move_is_valid(vars, vars->player_pos_x - 1, vars->player_pos_y))
		move_player(vars, keycode);
	else if (keycode == RIGHT && move_is_valid(vars, vars->player_pos_x + 1, vars->player_pos_y))
		move_player(vars, keycode);
	else
		ft_printf("bad input: %d\n", keycode);
	return (0);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_putendl("Closed window");
	exit (0);
}
