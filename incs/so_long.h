/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:46:07 by gudias            #+#    #+#             */
/*   Updated: 2022/03/30 16:02:54 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "../libs/libft/includes/libft.h"

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

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

void	exit_msg(char *msg);
int		key_input(int keycode, t_vars *vars);
int		close_window(t_vars *vars);

#endif
