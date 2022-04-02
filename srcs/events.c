/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:05:24 by gudias            #+#    #+#             */
/*   Updated: 2022/04/02 02:20:32 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_input(int keycode, t_vars *vars)
{
	if (keycode == UP && vars->player_pos_y>1 && vars->map[vars->player_pos_y - 1][vars->player_pos_x] != '1')
	{
		ft_printf("UP %d\n", keycode);
	}
	else if (keycode == DOWN && vars->player_pos_y<vars->map_h-2 && vars->map[vars->player_pos_y + 1][vars->player_pos_x] != '1')
		ft_printf("DOWN %d\n", keycode);
	else if (keycode == LEFT && vars->player_pos_x>1 && vars->map[vars->player_pos_y][vars->player_pos_x - 1] != '1')
		ft_printf("LEFT %d\n", keycode);
	else if (keycode == RIGHT && vars->player_pos_x<vars->map_w - 2 && vars->map[vars->player_pos_y][vars->player_pos_x + 1] != '1')
		ft_printf("RIGHT %d\n", keycode);
	else
		ft_printf("input %d\n", keycode);
	return (0);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_putendl("Closed window");
	exit (0);
}
