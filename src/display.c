/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:28:41 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/08 14:12:58 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void display_string(t_fractal *fractal, int x, int *y, char *str)
{
	//mlx_string_put(fractal->mlx, fractal->win, 20, 30, color, "Test string display");
	mlx_string_put(fractal->mlx, fractal->win, x, *y, WHITE, str);
	*y += LINE_LENGTH;
}

static void display_shift(t_fractal *fractal, int x, int *y)
{

	display_string(fractal, x, y, "left arrow : shift left");
	display_string(fractal, x, y, "right arrow : shift right");
	display_string(fractal, x, y, "bottom arrow : shift bottom");
	display_string(fractal, x, y, "up arrow : shift up");
}

static void display_zoom (t_fractal *fractal, int x, int *y)
{
	display_string(fractal, x, y, "wheel up : zoom in");
	display_string(fractal, x, y, "wheel down : zoom out");
}

int display_commands(t_fractal *fractal)
{
	int x = WIDTH / 2;
	int y = 30;
	t_img background;

	mlx_destroy_image(fractal->mlx, fractal->img.img);
	background.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length, &background.endian);
	fractal->img = background;
	mlx_put_image_to_window(fractal->mlx, fractal->win, background.img, 0, 0);
	if (fractal->set == 0)
		display_string(fractal, x, &y, "----- MANDELBROT SET ------");
	else if (fractal->set == 1)
		display_string(fractal, x, &y, "----- JULIA SET -------");
	display_shift(fractal, x, &y);
	display_zoom(fractal, x, &y);
	return (0);
}
