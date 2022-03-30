/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:05:24 by gudias            #+#    #+#             */
/*   Updated: 2022/03/30 14:40:47 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_input(int keycode, t_vars *vars)
{
	if (keycode == UP)
		ft_printf("UP %d\n", keycode);
	else if (keycode == DOWN)
		ft_printf("DOWN %d\n", keycode);
	else if (keycode == LEFT)
		ft_printf("LEFT %d\n", keycode);
	else if (keycode == RIGHT)
		ft_printf("RIGHT %d\n", keycode);
	else
		ft_printf("input %d\n", keycode);
	return (0);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_putendl("Closed window");
	exit (0);
}
