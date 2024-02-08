/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:31 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/08 13:33:25 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void calculate_and_put_pixels(t_fractal *fractal)
{
	t_pixel px;
	int color;
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			px.x = i;
			px.y = j;
			//int color = calculate_mandelbrot(px, fractal);
			if (fractal->set == 0)
				color = calculate_mandelbrot(px, fractal);
			else if (fractal->set == 1)
				color = calculate_julia(px, fractal);
			if (color)
				my_mlx_pixel_put(&fractal->img, px.x, px.y, color);
			//0x00FF0A80
		}
	}
}

static void init_struct(t_fractal *fractal, t_img img)
{
	fractal->img = img;
	//fractal->colorset = 0x0011FC92;
	//fractal->colorset = 0x00121212;
	fractal->colorset = 0x00A81513;
	//fractal->colorset = 0x00ffef7a;
	//fractal->colorset = 0x00275b55;
	fractal->xmin = -2.1;
	fractal->xmax = 0.6;
	fractal->ymin = -1.2;
	fractal->ymax = 1.2;
	fractal->zoom = 1;
	fractal->max_iterations = 40;
	if (fractal->set == 1)
		fractal->shiftx = 0.7;
	else 
		fractal->shiftx = 0;
	fractal->shifty = 0;
	fractal->current_point.real = fractal->xmin;
	fractal->current_point.imaginary = fractal->ymin;

}

void draw_fractal(t_fractal *fractal)
{
	t_img img;

	img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	init_struct(fractal, img);
	calculate_and_put_pixels(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, img.img, 0, 0);
	display_commands(fractal);

}


t_complex rescale_pixel(t_pixel px, t_fractal *fractal)
{
	t_complex point;

	point.real = (px.x * (fractal->xmax - fractal->xmin) / WIDTH) + fractal->xmin;
	point.real = point.real * fractal->zoom + fractal->shiftx;
	point.imaginary = (px.y * (fractal->ymax - fractal->ymin) / HEIGHT) + fractal->ymin;
	point.imaginary = -point.imaginary * fractal->zoom + fractal->shifty;
	return point;
}

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));

	*(unsigned int*)dst = color;
}
