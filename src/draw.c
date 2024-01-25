/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:31 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/25 13:18:01 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void calculate_and_put_pixels(t_fractal *fractal)
{
	t_pixel px;	
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			px.x = i;
			px.y = j;
			int color = calculate_mandelbrot(px, fractal);
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
	fractal->xmin = -2.1;
	fractal->xmax = 0.6;
	fractal->ymin = -1.2;
	fractal->ymax = 1.2;
	fractal->zoom = 1;
	fractal->shiftx = 0;
	fractal->shifty = 0;
	calculate_and_put_pixels(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, img.img, 0, 0);

}

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));

	*(unsigned int*)dst = color;
}

