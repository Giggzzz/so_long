/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:54:11 by gudias            #+#    #+#             */
/*   Updated: 2022/04/05 10:34:06 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_ennemy(t_vars *vars)
{
	int	dx;
	int	dy;

}

void	move_player(t_vars *vars, int key)
{
	vars->movecount++;
	//vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
	draw_tile(vars, vars->player_pos_x, vars->player_pos_y);
	if (key == UP)
		vars->player_pos_y--;
	else if (key == DOWN)
		vars->player_pos_y++;
	else if (key == LEFT)
		vars->player_pos_x--;
	else if (key == RIGHT)
		vars->player_pos_x++;
	draw_player(vars);
	if (vars->map[vars->player_pos_y][vars->player_pos_x] == 'C')
	{
		vars->map[vars->player_pos_y][vars->player_pos_x] = 'L';
		vars->coinleft--;
	}
	else if (vars->map[vars->player_pos_y][vars->player_pos_x] == 'E' && \
			vars->coinleft == 0)
		exit_win(vars);
	else if (vars->map[vars->player_pos_y][vars->player_pos_x] == 'X')
		exit_loose(vars);

	refresh_score(vars);
}
