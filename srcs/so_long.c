/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:48:31 by gudias            #+#    #+#             */
/*   Updated: 2022/03/28 18:03:09 by gudias           ###   ########.fr       */
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
	window = mlx_new_window(mlx, 300, 200, "42 | so_long");
	if (!window)
		return (1);

	mlx_loop(mlx);
	
	//mlx_pixel_put(mlx, window, x, y, int color);
	//mlx_string_put(mlx, win, x, y, color, char *str);

	//img = mlx_new_image(mlx, w, h);
	//mlx_put_image_to_window(mlx, win, img, x, y);

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
