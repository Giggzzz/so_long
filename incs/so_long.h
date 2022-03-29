/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:46:07 by gudias            #+#    #+#             */
/*   Updated: 2022/03/30 01:21:20 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG
# include <mlx.h>
# include "../libs/libft/includes/libft.h"

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

int	key_input(int keycode, t_vars *vars);

#endif
