/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:13:21 by gudias            #+#    #+#             */
/*   Updated: 2022/04/06 18:59:34 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_vars *vars, int x, int y, char *path)
{
	void	*img;
	int	width;
	int	height;

	img = mlx_xpm_file_to_image(vars->mlx, path, &width, &height);
	if (!img)
		exit_msg("couldn't load sprite");
	mlx_put_image_to_window(vars->mlx, vars->win, img, x*50, y*50);
	mlx_destroy_image(vars->mlx, img);
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
		draw_image(vars, vars->player_pos_x, vars->player_pos_y, "./assets/sprites/helmet50.xpm");
}

void	draw_tile(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
		draw_image(vars, x, y, "./assets/sprites/wallmid50.xpm");
	else if (vars->map[y][x] == '0')
		draw_image(vars, x, y, "./assets/sprites/ground_50.xpm");
	else if (vars->map[y][x] == 'C')
		draw_image(vars, x, y, "./assets/sprites/diamond50.xpm");
	else if (vars->map[y][x] == 'L')
		draw_image(vars, x, y, "./assets/sprites/grass50.xpm");
	else if (vars->map[y][x] == 'E')
		draw_image(vars, x, y, "./assets/sprites/beer50.xpm");
	else if (vars->map[y][x] == 'X')
		draw_image(vars, x, y, "./assets/sprites/skull50.xpm");
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
