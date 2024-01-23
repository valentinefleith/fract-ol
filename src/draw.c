/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:31 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/23 18:10:06 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int calculate_pixel_color(t_pixel px, t_fractal *fractal)
{
	double zoom = 400;
	double x1 = -2.1;
	double x2 = 0.6;
	double y1 = -1.2;
	double y2 = 1.2;
	t_complex point;
	point.real = ((px.x + x1)/ zoom - 3 * x2 - 0.2);
	//point.real = ((px.x + x1)/ zoom - 3 * x2 - 1.5) * 0.1;
	//point.real = (x / zoom + x1);
	point.imaginary = ((px.y + y1) / zoom - y2);
	//point.imaginary = ((px.y + y1) / zoom - y2 - 7) * 0.1;
	t_complex z;
	z.real = 0;
	z.imaginary = 0;
	int max = 4;
	for (int i = 0; i < 200; i++)
	{
		double tmp = z.real;
		z.real = (z.real * z.real) - (z.imaginary * z.imaginary) + point.real;
		z.imaginary = (2 * tmp * z.imaginary) + point.imaginary;
		if (z.real * z.real + z.imaginary * z.imaginary > max)
		{
			if (i)
				//return 0x0011FC92 * i;
				//return 0x00119EFC;
				//return 0x00119EFC;
				return fractal->colorset * i;
				//return colorset * i;
				//return 0x00FC11DD * i;
			return WHITE;
			//return 0x00FFFFFF;
		}
	}
	return 0;
}

void calculate_and_put_pixels(t_fractal *fractal)
{
	t_pixel px;	
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			px.x = i;
			px.y = j;
			int color = calculate_pixel_color(px, fractal);
			if (color)
				my_mlx_pixel_put(&fractal->img, px.x, px.y, color);
			//0x00FF0A80
		}
	}
}

void draw_fractal(t_fractal *fractal)
{
	t_img img;

	img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	fractal->img = img;
	fractal->colorset = 0x00119EFC;
	calculate_and_put_pixels(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, img.img, 0, 0);

}

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));

	*(unsigned int*)dst = color;
}

