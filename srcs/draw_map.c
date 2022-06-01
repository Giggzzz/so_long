/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:13:21 by gudias            #+#    #+#             */
/*   Updated: 2022/05/31 19:02:32 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_image(t_game *game, int x, int y, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!img)
		exit_msg(game, "couldn't load sprite");
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILESIZE, y * TILESIZE);
	mlx_destroy_image(game->mlx, img);
}

void	refresh_score(t_game *game)
{
	char	*moves;
	char	*coins;

	draw_tile(game, 2, 0);
	draw_tile(game, 4, 0);
	moves = ft_itoa(game->movecount);
	coins = ft_itoa(game->coinleft);
	mlx_string_put(game->mlx, game->win, 68, 20, 0xFF0000, moves);
	mlx_string_put(game->mlx, game->win, 132, 20, 0xFFFF00, coins);
	ft_printf("Move count: %d\n", game->movecount);
	free(moves);
	free(coins);
}

void	draw_player(t_game *game)
{
	draw_image(game, game->player_x, game->player_y, game->player_img);
}

void	draw_tile(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		draw_image(game, x, y, WALL);
	else
	{
		draw_image(game, x, y, GROUND);
		if (game->map[y][x] == 'C')
			draw_image(game, x, y, COIN);
		else if (game->map[y][x] == 'E')
			draw_image(game, x, y, game->exit_img);
		else if (game->map[y][x] == 'X')
			draw_image(game, x, y, game->enemy_img);
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
	draw_player(game);
	mlx_string_put(game->mlx, game->win, 32, 20, 0xFF0000, "Moves: ");
	mlx_string_put(game->mlx, game->win, 96, 20, 0xFFFF00, "Coins: ");
	refresh_score(game);
}
