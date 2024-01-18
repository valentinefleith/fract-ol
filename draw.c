/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:31 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/18 22:42:59 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int calculate_pixel_color(int x, int y)
{
	t_point zero;
	//t_point point;

	zero.x = WIDTH / 2;
	zero.y = HEIGHT / 2;
	t_point point = {x, y, x - zero.x, y - zero.y};
	int z = 0;
	int max = 100000;
	for (int i = 0; i < 100; i++)
	{
		z = (z * z) + point.real + point.imaginary;
		if (z > max)
		{
			return 0xFFFFFFFF;
		}
	}
	return 0;
}

void calculate_and_put_pixels(t_data *img)
{
	
	for (int i = 0; i < 800; i++)
	{
		for (int j = 0; j < 800; j++)
		{
			int color = calculate_pixel_color(i, j);
			if (color)
				my_mlx_pixel_put(img, i, j, color);
			//0x00FF0A80
		}
	}
}

void draw_fractal(t_vars vars)
{
	t_data img;

	img.img = mlx_new_image(vars.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	calculate_and_put_pixels(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));

	*(unsigned int*)dst = color;
}

