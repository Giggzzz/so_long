/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:46:07 by gudias            #+#    #+#             */
/*   Updated: 2022/04/09 01:34:11 by gudias           ###   ########.fr       */
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
# define ENNEMY "./assets/sprites/skull50.xpm"
# define PLAYER "./assets/sprites/helmet50.xpm"

# if defined(__linux__)
#  define UP 119
#  define DOWN 115
#  define LEFT 97
#  define RIGHT 100
#  define ESCAPE 65307
# elif defined(__APPLE__)
#  define UP 13
#  define DOWN 1
#  define LEFT 0
#  define RIGHT 2
#  define ESCAPE 53
# endif

typedef struct	s_pos
{
	int	x;
	int	y;
}		t_pos;


typedef struct	s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int	map_w;
	int	map_h;
	int	player_x;
	int	player_y;
	int	enemy_x;
	int	enemy_y;
	int	exit;
	int	coinleft;
	int	movecount;
}		t_game;

void	move_player(t_game *game, int key);
void	draw_map(t_game *game);
void	draw_tile(t_game *game, int x, int y);
void	draw_player(t_game *game);
void	refresh_score(t_game *game);
char	**readcheck_map(char *mapname, t_game *game);
void	exit_msg(char *msg);
void	exit_win(t_game *game);
void	exit_loose(t_game *game);
int		key_input(int keycode, t_game *game);
int		close_window(t_game *game);

#endif
