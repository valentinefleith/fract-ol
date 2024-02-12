/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:28:41 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/12 15:34:05 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void display_string_centered(t_fractal *fractal, int *y, char *str)
{
	int x = (WIDTH - ft_strlen(str)*6) / 2;
	mlx_string_put(fractal->mlx, fractal->win, x, *y, WHITE, str);
	*y += LINE_LENGTH;
}

static void display_command_list(t_fractal *fractal, int *y)
{

	display_string_centered(fractal, y, "Arrows : Moving");
	display_string_centered(fractal, y, "Wheel : Zoom");
	display_string_centered(fractal, y, "p : Add precision");
	display_string_centered(fractal, y, "m : Decrease precision");
	display_string_centered(fractal, y, "c : Change colorset");
	display_string_centered(fractal, y, "r : Reset");
}


void display_help(t_fractal *fractal)
{
	mlx_string_put(fractal->mlx, fractal->win, 20, 30, BLACK, "Press h to display help");
}

//void display_julias_param(t_fractal *fractal)
//{
//	mlx_string_put(fractal->mlx, fractal->win, WIDTH - 20, 30, BLACK, "Current julia point : ");
//}

int display_commands(t_fractal *fractal)
{
	int y = 30;
	t_img background;
	
	fractal->help = 1;
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	background.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	// TODO : check Malloc
	// /!\ LEAKS (free everything)
	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length, &background.endian);
	fractal->img = background;
	mlx_put_image_to_window(fractal->mlx, fractal->win, background.img, 0, 0);
	if (fractal->set == 0)
		display_string_centered(fractal, &y, "------- MANDELBROT SET -------");
	else if (fractal->set == 1)
		display_string_centered(fractal, &y, "------- JULIA SET -------");
	y += LINE_LENGTH;
	display_command_list(fractal, &y);
	//display_zoom(fractal, x, &y);
	return (0);
}
