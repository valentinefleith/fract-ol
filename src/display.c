/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:28:41 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/07 15:53:14 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void display_string(t_fractal *fractal, int x, int *y, char *str)
{
	//mlx_string_put(fractal->mlx, fractal->win, 20, 30, color, "Test string display");
	mlx_string_put(fractal->mlx, fractal->win, x, *y, BLACK, str);
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
	display_string(fractal, x, y, "P / wheel up : zoom in");
	display_string(fractal, x, y, "M / wheel down : zoom out");
}

void display_commands(t_fractal *fractal)
{
	int x = 30;
	int y = 30;
	if (fractal->set == 0)
		display_string(fractal, x, &y, "----- MANDELBROT SET ------");
	else if (fractal->set == 1)
		display_string(fractal, x, &y, "----- JULIA SET -------");
	display_shift(fractal, x, &y);
	display_zoom(fractal, x, &y);
}
