/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:31 by vafleith          #+#    #+#             */
/*   Updated: 2024/03/16 00:04:37 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_refresh(t_fractal *fractal)
{
	t_img	new_img;

	mlx_destroy_image(fractal->mlx, fractal->img.img);
	new_img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (new_img.img == NULL)
	{
		free_window(fractal);
		exit(1);
	}
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel,
			&new_img.line_length, &new_img.endian);
	fractal->img = new_img;
	calculate_and_put_pixels(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, new_img.img, 0, 0);
	display_standard(fractal);
}

void	calculate_and_put_pixels(t_fractal *fractal)
{
	t_pixel	px;
	int		color;

	px.x = 0;
	while (px.x < WIDTH)
	{
		px.y = 0;
		while (px.y < HEIGHT)
		{
			if (fractal->set == 0)
				color = calculate_mandelbrot(px, fractal);
			else if (fractal->set == 1)
				color = calculate_julia(px, fractal);
			else if (fractal->set == 2)
				color = calculate_burning_ship(px, fractal);
			else if (fractal->set == 3)
				color = calculate_multibrot(px, fractal);
			else if (fractal->set == 4)
				color = calculate_julia_burning_ship(px, fractal);
			my_mlx_pixel_put(&fractal->img, px.x, px.y, color);
			px.y++;
		}
		px.x++;
	}
}
