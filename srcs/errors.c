/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:39:36 by gudias            #+#    #+#             */
/*   Updated: 2022/04/05 13:40:03 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	black_screen(t_vars *vars)
{
	int	x;
	int	y;
	t_img	img;

	img.img = mlx_new_image(vars->mlx, vars->map_w * 50, vars->map_h * 50);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

	y = 0;
	while (y < vars->map_h*50)
	{
		x = 0;
		while (x < vars->map_w*50)
		{
			my_mlx_pixel_put(&img, x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

void	exit_msg(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	//free
	exit (0);
}

void	exit_win(t_vars *vars)
{
	ft_printf("YOU WIN !\nIt tooks you %d moves..\n", vars->movecount);
	//black_screen(vars);	
	mlx_string_put(vars->mlx, vars->win, (vars->map_w)*25, (vars->map_h)*25, 0x00FF00, "YOU WIN!");
	//sleep(10);
	//exit (0);
}

void	exit_loose(t_vars *vars)
{
	ft_putendl("YOU GOT KILLED! GAME OVER...\n");
	//black_screen(vars);	
	mlx_string_put(vars->mlx, vars->win, (vars->map_w)*25, (vars->map_h)*25, 0xFF0000, "GAME OVER!");	
	//sleep(10);
	//exit (0);
}

//should free all before exit..
