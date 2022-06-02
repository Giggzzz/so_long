/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:46:07 by gudias            #+#    #+#             */
/*   Updated: 2022/06/02 13:43:45 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "../libs/libft/includes/libft.h"
# include <fcntl.h>

# include "sprites.h"
# include "keys.h"

# define MAPSDIR "./assets/maps"
# define TILESIZE 32

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_w;
	int		map_h;
	int		player_x;
	int		player_y;
	char	*player_img;
	int		player_dir;
	int		player_anim;
	int		enemy_x;
	int		enemy_y;
	char	*enemy_img;
	int		enemy_dir;
	int		enemy_anim;
	int		exit_x;
	int		exit_y;
	char	*exit_img;
	int		exit;
	int		coinleft;
	int		movecount;
	int		end;
}		t_game;

char	**get_map(char *mapname, t_game *game);
void	get_line_data(char *line, int i, t_game *game);
int		check_extension(char *mapname);
int		check_walls(char *line);
void	check_line(char *line, t_game *game);
void	check_map_is_valid(t_game *game);

void	draw_map(t_game *game);
void	draw_tile(t_game *game, int x, int y);
void	draw_player(t_game *game);
void	refresh_score(t_game *game);

int		key_input(int key, t_game *game);
int		update_frame(t_game *game);

void	check_player_move(t_game *game, int key);
void	move_enemy(t_game *game);

void	anim_player_idle(t_game *game);
void	anim_enemy_idle(t_game *game);
void	anim_exit_open(t_game *game);
void	change_player_direction(t_game *game);

void	exit_msg(t_game *game, char *msg);
void	exit_win(t_game *game);
void	exit_loose(t_game *game);
int		close_window(t_game *game);
void	close_game(t_game *game);

#endif
