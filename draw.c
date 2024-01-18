/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:31 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/18 20:22:28 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void calculate_and_put_pixels(t_data *img)
{
	for (int i = 20; i < 400; i++)
	{
		for (int j = 20; j < 400; j++)
		{
			my_mlx_pixel_put(img, i, j, 0x00FF0A80);
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

