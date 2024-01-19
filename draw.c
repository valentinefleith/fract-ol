/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:31 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/19 10:55:34 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include <stdio.h>

int calculate_pixel_color(int x, int y)
{
	double zoom = 200;
	double x1 = -2.1;
	double x2 = 0.6;
	double y1 = -1.2;
	double y2 = 1.2;
	//t_complex point = {(float)(x - (WIDTH / 2))/zoom + x1, (float)(y - (HEIGHT / 2))/zoom + y1};
	//t_complex point = {(float)(x /zoom + x1), (float)(y /zoom + y1)};
	t_complex point;
	point.real = ((x + x1)/ zoom - 1.8);
	//point.real = (x / zoom + x1);
	point.imaginary = ((y + y1) / zoom - 1.2);
	//printf("x = %i, y = %i, valeur reelle = %f, valeur imaginaire %f\n", x, y, point.real, point.imaginary);
	t_complex z;
	z.real = 0;
	z.imaginary = 0;
	//int max = 214748360;
	int max = 4;
	for (int i = 0; i < 100; i++)
	{
		double tmp = z.real;
		z.real = (z.real * z.real) - (z.imaginary * z.imaginary) + point.real;
		z.imaginary = (2 * tmp * z.imaginary) + point.imaginary;
		if (z.real * z.real + z.imaginary * z.imaginary > max)
		{
			return 0xFFFFFFFF;
		}
	}
	return 0;
}

void calculate_and_put_pixels(t_data *img)
{
	
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
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

	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
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

