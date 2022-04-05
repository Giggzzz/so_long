/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:46:07 by gudias            #+#    #+#             */
/*   Updated: 2022/04/05 13:28:07 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "../libs/libft/includes/libft.h"
# include <fcntl.h>

# define MAPSDIR "./assets/maps"

# if defined(__linux__)
#  define UP 119
#  define DOWN 115
#  define LEFT 97
#  define RIGHT 100
# elif defined(__APPLE__)
#  define UP 13
#  define DOWN 1
#  define LEFT 0
#  define RIGHT 2
# endif

typedef struct	s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int	map_w;
	int	map_h;
	int	player_pos_x;
	int	player_pos_y;
	int	exit_pos_x;
	int	exit_pos_y;
	int	coinleft;
	int	movecount;
}		t_vars;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	move_player(t_vars *vars, int key);
void	draw_map(t_vars *vars);
void	draw_tile(t_vars *vars, int x, int y);
void	draw_player(t_vars *vars);
void	refresh_score(t_vars *vars);
char	**readcheck_map(char *mapname, t_vars *vars);
void	exit_msg(char *msg);
void	exit_win(t_vars *vars);
void	exit_loose(t_vars *vars);
int		key_input(int keycode, t_vars *vars);
int		close_window(t_vars *vars);

#endif
