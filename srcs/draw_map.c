/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:13:21 by gudias            #+#    #+#             */
/*   Updated: 2022/04/02 01:25:47 by gudias           ###   ########.fr       */
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

void	draw_tile(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
		draw_square(vars, x, y, 0x424242);
	else if (vars->map[y][x] == '0')
		draw_square(vars, x, y, 0xF0F0F0);
	else if (vars->map[y][x] == 'C')
		draw_square(vars, x, y, 0xFFFF00);
	else if (vars->map[y][x] == 'E')
		draw_square(vars, x, y, 0x0000FF);
	else if (vars->map[y][x] == 'P')
		draw_square(vars, x, y, 0x00FF00);
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
}
