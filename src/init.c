/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 23:08:40 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/13 12:19:01 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_struct(t_fractal *fractal, t_img img)
{
	fractal->img = img;
	fractal->colornb = 0;
	init_palette(fractal);
	fractal->colorset = fractal->palette[0];
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

void	init_palette(t_fractal *fractal)
{
	fractal->palette[0] = 0xf4dbd6;
	fractal->palette[1] = 0xf9e2af;
	fractal->palette[2] = 0xf5bde6;
	fractal->palette[3] = 0xc6a0f6;
	fractal->palette[4] = 0xed8796;
	fractal->palette[5] = 0xee99a0;
	fractal->palette[6] = 0xf5a97f;
	fractal->palette[7] = 0xb7bdf8;
	fractal->palette[8] = 0x74c7ec;
	fractal->palette[9] = 0xcd8604;
}

void	init_fractal(t_fractal *fractal)
{
	t_img	img;

	img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	// TODO : verify that malloc worked
	// /!\ LEAKS (free everything)
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	init_struct(fractal, img);
	calculate_and_put_pixels(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, img.img, 0, 0);
	display_standard(fractal);
}

void	init_hook(t_fractal *fractal)
{
	mlx_mouse_hook(fractal->win, mouse_events, fractal);
	mlx_key_hook(fractal->win, key_events, fractal);
	mlx_hook(fractal->win, 17, 0, exit_program, fractal);
	if (fractal->set == 1)
		mlx_hook(fractal->win, 6, 1L << 6, mouse_move, fractal);
	mlx_loop(fractal->mlx);
}
