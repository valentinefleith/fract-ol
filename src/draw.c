/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:31 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/12 20:27:40 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void calculate_and_put_pixels(t_fractal *fractal)
{
	t_pixel px;
	int color;
	int i = 0;
	while (i < WIDTH)
	{
		int j = 0;
		while (j < HEIGHT)
		{
			px.x = i;
			px.y = j;
			if (fractal->set == 0)
				color = calculate_mandelbrot(px, fractal);
			else if (fractal->set == 1)
				color = calculate_julia(px, fractal);
			else if (fractal->set == 2)
				color = calculate_burning_ship(px, fractal);
			if (color)
				my_mlx_pixel_put(&fractal->img, px.x, px.y, color);
			//0x00FF0A80
			j++;
		}
		i++;
	}
}

void init_struct(t_fractal *fractal, t_img img)
{
	fractal->img = img;
	// CATPUCCIN
	fractal->colorset = 0xcba6f7;
	//fractal->colorset = 0xf9e2af;
	//fractal->colorset = 0xf0c6c6;
	//
	//fractal->colorset = 0x00121212; // dark
	//fractal->colorset = 0xFFF3EAEA; // bright
	fractal->brightness = 3;
	fractal->xmin = -2.1;
	fractal->xmax = 0.6;
	fractal->ymin = -1.2;
	fractal->ymax = 1.2;
	fractal->zoom = 1;
	fractal->max_iterations = MIN_ITERATIONS;
	if (fractal->set == 1)
		fractal->shiftx = 0.7;
	else 
		fractal->shiftx = 0;
	fractal->shifty = 0;
	fractal->current_point.real = 0.285;
	fractal->current_point.imaginary = 0.01;
	fractal->help = 0;

}

void init_fractal(t_fractal *fractal)
{
	t_img img;

	img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	// TODO : verify that malloc worked
	// /!\ LEAKS (free everything)
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	init_struct(fractal, img);
	calculate_and_put_pixels(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, img.img, 0, 0);
	display_standard(fractal);

}


t_complex rescale_pixel(t_pixel px, t_fractal *fractal)
{
	t_complex point;

	point.real = (px.x * (fractal->xmax - fractal->xmin) / WIDTH) + fractal->xmin;
	point.real = point.real * fractal->zoom + fractal->shiftx;
	point.imaginary = (px.y * (fractal->ymax - fractal->ymin) / HEIGHT) + fractal->ymin;
	if (fractal->set == 2)
		point.imaginary = point.imaginary * fractal->zoom + fractal->shifty;
	else
		point.imaginary = -point.imaginary * fractal->zoom + fractal->shifty;
	return point;
}

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));

	*(unsigned int*)dst = color;
}
