/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:28:41 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/09 11:55:54 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void display_string(t_fractal *fractal, int *y, char *str)
{
	int x = (WIDTH - ft_strlen(str)*6) / 2;
	mlx_string_put(fractal->mlx, fractal->win, x, *y, WHITE, str);
	*y += LINE_LENGTH;
}

static void display_command_list(t_fractal *fractal, int *y)
{

	display_string(fractal, y, "Arrows : Moving");
	display_string(fractal, y, "Wheel : Zoom");
	display_string(fractal, y, "p : Add precision");
	display_string(fractal, y, "m : Decrease precision");
	display_string(fractal, y, "c : Change colorset");
	display_string(fractal, y, "r : Reset");
}


void display_help(t_fractal *fractal)
{
	mlx_string_put(fractal->mlx, fractal->win, 20, 30, BLACK, "Press h to display help");
}

int display_commands(t_fractal *fractal)
{
	//int x = WIDTH / 2;
	int y = 30;
	t_img background;
	
	fractal->help = 1;
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	background.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length, &background.endian);
	fractal->img = background;
	mlx_put_image_to_window(fractal->mlx, fractal->win, background.img, 0, 0);
	if (fractal->set == 0)
		display_string(fractal, &y, "------- MANDELBROT SET -------");
	else if (fractal->set == 1)
		display_string(fractal, &y, "------- JULIA SET -------");
	y += LINE_LENGTH;
	display_command_list(fractal, &y);
	//display_zoom(fractal, x, &y);
	return (0);
}
