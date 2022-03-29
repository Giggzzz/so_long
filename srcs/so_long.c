/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:48:31 by gudias            #+#    #+#             */
/*   Updated: 2022/03/29 00:23:00 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	window = mlx_new_window(mlx, 800, 600, "42 | so_long");
	if (!window)
		return (1);
	
	int	x, y = 0;
	while (y<=300)
	{
		x = 0;
		while (x<400)
		{
			if (x>175 && x<225 && y>125 && y<175)
				mlx_pixel_put(mlx, window, 200+x, 150+y, 0xFFFF00);
			else if (x>100 && x<300 && y>75 && y<225)
				mlx_pixel_put(mlx, window, 200+x, 150+y,0x00FF00);
			else
				mlx_pixel_put(mlx, window, 200+x, 150+y, 0xFF0000);
			x++;
		}
		y++;
	}
	//mlx_pixel_put(mlx, window, 5, 5, 0xFF0000);
	mlx_loop(mlx);
	
	//mlx_string_put(mlx, window, 50, 50, 0xFF0000, "HELLOOW");

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

	//int mlx_key_hook(window, int(*fn)(), void *param);
	//int mlx_mouse_hook(window, int (*fn)(), void *param);
	//int mlx_expose_hook(window, int (*fn)(), void *param);
	//int mlx_loop_hook(mlx, int (*fn)(), void *param);

	//mlx_destroy_image(mlx, img);
	//mlx_clear_window(mlx, window);
	//mlx_destroy_window(mlx, window);

	return (0);
}
