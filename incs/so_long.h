/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:46:07 by gudias            #+#    #+#             */
/*   Updated: 2022/06/01 14:20:39 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "../libs/libft/includes/libft.h"
# include <fcntl.h>

# define MAPSDIR "./assets/maps"
# define TILESIZE 32

# define WALL "./assets/sprites/wallmid.xpm"
# define GROUND "./assets/sprites/ground.xpm"
# define COIN "./assets/sprites/money.xpm"
# define EXIT "./assets/sprites/exit1.xpm"
# define EXIT2 "./assets/sprites/exit2.xpm"
# define EXIT3 "./assets/sprites/exit3.xpm"
# define EXIT4 "./assets/sprites/exit4.xpm"
# define EXIT5 "./assets/sprites/exit5.xpm"
# define EXIT6 "./assets/sprites/exit6.xpm"
# define PLAYER_RIGHT1 "./assets/sprites/dwarf_right1.xpm"
# define PLAYER_RIGHT2 "./assets/sprites/dwarf_right2.xpm"
# define PLAYER_RIGHT3 "./assets/sprites/dwarf_right3.xpm"
# define PLAYER_RIGHT4 "./assets/sprites/dwarf_right4.xpm"
# define PLAYER_RIGHT5 "./assets/sprites/dwarf_right5.xpm"
# define PLAYER_LEFT1 "./assets/sprites/dwarf_left1.xpm"
# define PLAYER_LEFT2 "./assets/sprites/dwarf_left2.xpm"
# define PLAYER_LEFT3 "./assets/sprites/dwarf_left3.xpm"
# define PLAYER_LEFT4 "./assets/sprites/dwarf_left4.xpm"
# define PLAYER_LEFT5 "./assets/sprites/dwarf_left5.xpm"
# define ENEMY_RIGHT1 "./assets/sprites/ghoul_right1.xpm"
# define ENEMY_RIGHT2 "./assets/sprites/ghoul_right2.xpm"
# define ENEMY_RIGHT3 "./assets/sprites/ghoul_right3.xpm"
# define ENEMY_RIGHT4 "./assets/sprites/ghoul_right4.xpm"
# define ENEMY_LEFT1 "./assets/sprites/ghoul_left1.xpm"
# define ENEMY_LEFT2 "./assets/sprites/ghoul_left2.xpm"
# define ENEMY_LEFT3 "./assets/sprites/ghoul_left3.xpm"
# define ENEMY_LEFT4 "./assets/sprites/ghoul_left4.xpm"

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
