/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:46:58 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/12 19:12:40 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
#include <inttypes.h>
#include <stdio.h>

int key_events(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ESC)
		return exit_program(fractal);
	if (keycode == KEY_C)
		return change_colors(fractal);
	if (keycode == KEY_P || keycode == KEY_M)
		return change_precision(fractal, keycode);
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT || keycode == KEY_UP || keycode == KEY_DOWN)
		return handle_shift(fractal, keycode);
	if (keycode == KEY_R)
	{
		init_struct(fractal, fractal->img);
		fractal_refresh(fractal);
	}
	if (keycode == KEY_B || keycode == KEY_D)
		return change_brightness(fractal, keycode);
	if (keycode == KEY_H && fractal->help == 0) 
		return display_commands(fractal);
	if (keycode == KEY_H && fractal->help == 1)
	{
		fractal->help = 0;
		fractal_refresh(fractal);
	}
	return 0;
}

int mouse_events(int button, int x, int y, t_fractal *fractal)
{
	if (button == 5 )
		return zoom_out(fractal);
	if (button == 4)
		return zoom_in(fractal, x, y);
	if (button == 1 && fractal->set == 1)
		return change_julias_shape(x, y, fractal);
	return 0;
}

int handle_shift(t_fractal *fractal, int keycode)
{
	if (keycode == KEY_RIGHT)
		return shiftreal(fractal, '+');
	if (keycode == KEY_LEFT)
		return shiftreal(fractal, '-');
	if (keycode == KEY_UP)
		return shiftimaginary(fractal, '-');
	if (keycode == KEY_DOWN)
		return shiftimaginary(fractal, '+');
	return 0;
}


int change_precision(t_fractal *fractal, int keycode)
{
	if (keycode == KEY_P)
	{
		if (fractal->max_iterations < MAX_ITERATIONS)
			fractal->max_iterations++;
	}
	if (keycode == KEY_M)
	{
		if (fractal->max_iterations > MIN_ITERATIONS)
			fractal->max_iterations--;
	}
	fractal_refresh(fractal);
	return 0;
}

int change_brightness(t_fractal *fractal, int keycode)
{
	if (keycode == KEY_B)
		fractal->brightness--;
	if (keycode == KEY_D)
		fractal->brightness++;
	fractal_refresh(fractal);
	return 0;
}

int change_colors(t_fractal *fractal)
{
	//int colors[] = {0x0011FC92, 0x00119EFC, 0x00FCBE11, 0x00AB3434};
	//fractal->colorset = fractal->colorset * 0.7 + 5;
	//fractal->colorset = fractal->colorset * 1.5 - 560;
	fractal->colorset = fractal->colorset * 1.01 + 5;
	printf("%X\n", fractal->colorset);
	fractal_refresh(fractal);	
	return 0;
}
