/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:46:07 by gudias            #+#    #+#             */
/*   Updated: 2022/04/23 12:47:03 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "../libs/libft/includes/libft.h"
# include <fcntl.h>

# define MAPSDIR "./assets/maps"
# define TILESIZE 50

# define WALL "./assets/sprites/wallmid50.xpm"
# define GROUND "./assets/sprites/ground50.xpm"
# define COIN "./assets/sprites/diamond50.xpm"
# define LOOTED "./assets/sprites/grass50.xpm"
# define EXIT "./assets/sprites/beer50.xpm"
# define ENEMY_LEFT "./assets/sprites/skull50.xpm"
# define ENEMY_RIGHT "./assets/sprites/skull50.xpm"
# define PLAYER_RIGHT "./assets/sprites/dwarf_right50.xpm"
# define PLAYER_LEFT "./assets/sprites/dwarf_left50.xpm"

# if defined(__linux__)
#  define K_UP 119
#  define K_DOWN 115
#  define K_LEFT 97
#  define K_RIGHT 100
#  define K_ESC 65307
# elif defined(__APPLE__)
#  define K_UP 13
#  define K_DOWN 1
#  define K_LEFT 0
#  define K_RIGHT 2
#  define K_ESC 53
# endif

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
	int		enemy_x;
	int		enemy_y;
	int		exit;
	int		coinleft;
	int		movecount;
	int		end;
}		t_game;

void	check_player_move(t_game *game, int key);
void	move_enemy(t_game *game);

void	draw_map(t_game *game);
void	draw_tile(t_game *game, int x, int y);
void	draw_player(t_game *game, char *img);
void	refresh_score(t_game *game);

char	**get_map(char *mapname, t_game *game);
void	get_line_data(char *line, int i, t_game *game);
int		check_extension(char *mapname);
int		check_walls(char *line);
void	check_line(char *line, t_game *game);
void	check_map_is_valid(t_game *game);

int		key_input(int key, t_game *game);
int		update_frame(t_game *game);

void	exit_msg(t_game *game, char *msg);
void	exit_win(t_game *game);
void	exit_loose(t_game *game);
int		close_window(t_game *game);
void	close_game(t_game *game);

#endif
