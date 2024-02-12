/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:31 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/13 00:57:42 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_refresh(t_fractal *fractal)
{
	t_img	new_img;

	mlx_destroy_image(fractal->mlx, fractal->img.img);
	new_img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	// TODO : verify that malloc worked
	// /!\ LEAKS (free everything)
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel,
			&new_img.line_length, &new_img.endian);
	fractal->img = new_img;
	calculate_and_put_pixels(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, new_img.img, 0, 0);
	display_standard(fractal);
}

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
