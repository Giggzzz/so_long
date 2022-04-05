/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:48:31 by gudias            #+#    #+#             */
/*   Updated: 2022/04/05 18:07:27 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		exit_msg("bad arguments");
	
	vars.player_pos_x = -1;
	vars.exit_pos_x = -1;
	vars.coinleft = 0;
	vars.movecount = 0;

	vars.map = readcheck_map(argv[1], &vars);
	
	int i = -1;
	while (++i < vars.map_h)
		ft_putstr(vars.map[i]);

	vars.mlx = mlx_init();
	if (!vars.mlx)
		exit_msg("couldn't init mlx");
	vars.win = mlx_new_window(vars.mlx, vars.map_w*50, vars.map_h*50, "42 | so_long");
	if (!vars.win)
		exit_msg("couldn't create window");

	draw_map(&vars);

	void *img;
	char *path = "./assets/sprites/ground.xpm";
	int	width;
	int	height;

	img = mlx_xpm_file_to_image(vars.mlx, path, &width, &height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 50, 50);
	//mlx_key_hook(vars.win, key_input, &vars);
	mlx_hook(vars.win, 2, 0, key_input, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);

	mlx_loop(vars.mlx);
	return (0);
}

	//img = mlx_new_image(mlx, 50, 50);
	//mlx_put_image_to_window(mlx, window, img, 20, 20);

	//int pos = (y * sizeline + x * (bitperpixel /8);
	//char *mlx_get_data_addr(img, int *bit_per_pixel, int *sizeline, int *endian);
	//u int mlx_get_color_value(mlx, int color);

	//img = mlx_xpm_to_image(mlx, char **xpm_data, w, h);

	//char *path = "./img/test.xpm";
	//int img_w;
	//int img_h;
	//img = mlx_xpm_file_to_image(mlx, path, &img_w, &img_h);
	
	//void	mlx_hook(window, int x_event, mask, int (*fn)(), *param);
	//int mlx_key_hook(window, int(*fn)(), void *param);
	//int mlx_mouse_hook(window, int (*fn)(), void *param);
	//int mlx_expose_hook(window, int (*fn)(), void *param);
	//int mlx_loop_hook(mlx, int (*fn)(), void *param);

	//mlx_destroy_image(mlx, img);
	//mlx_clear_window(mlx, window);
	//mlx_destroy_window(mlx, window);

