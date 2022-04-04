/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:13:21 by gudias            #+#    #+#             */
/*   Updated: 2022/04/04 18:32:08 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_square(t_vars *vars, int x, int y, int color)
{
	int	i;
	int	j;
	
	j = 0;
	while (j < 50)
	{
		i = 0;
		while (i < 50)
		{
			mlx_pixel_put(vars->mlx, vars->win, (x*50) + i, (y*50) + j, color);
			i++;
		}
		j++;
	}
}

void	refresh_score(t_vars *vars)
{
	char	*moves;
	char	*coins;

	draw_tile(vars, 2, 0);
	moves = ft_itoa(vars->movecount);
	coins = ft_itoa(vars->coinleft);
	mlx_string_put(vars->mlx, vars->win, 100, 20, 0xFF0000, moves);
	mlx_string_put(vars->mlx, vars->win, 100, 40, 0xFFFF00, coins);
	free(moves);
	free(coins);
}

void	draw_player(t_vars *vars)
{
	draw_square(vars, vars->player_pos_x, vars->player_pos_y, 0x00FF00);
}

void	draw_tile(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
		draw_square(vars, x, y, 0x424242);
	else if (vars->map[y][x] == '0')
		draw_square(vars, x, y, 0xF0F0F0);
	else if (vars->map[y][x] == 'C')
		draw_square(vars, x, y, 0xFFFF00);
	else if (vars->map[y][x] == 'L')
		draw_square(vars, x, y, 0xC3C3C3);
	else if (vars->map[y][x] == 'E')
		draw_square(vars, x, y, 0x0000FF);
	else if (vars->map[y][x] == 'X')
		draw_square(vars, x, y, 0xFF0000);
}

void	draw_map(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map_h)
	{
		x = 0;
		while (x < vars->map_w)
		{
			draw_tile(vars, x, y);
			x++;
		}
		y++;
	}
	draw_player(vars);
	mlx_string_put(vars->mlx, vars->win, 50, 20, 0xFF0000, "Moves: ");
	mlx_string_put(vars->mlx, vars->win, 50, 40, 0xFFFF00, "Coins: ");
	refresh_score(vars);
}
