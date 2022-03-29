/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:05:24 by gudias            #+#    #+#             */
/*   Updated: 2022/03/30 01:20:06 by gudias           ###   ########.fr       */
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
	return (0);
}
