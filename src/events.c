/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:46:58 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/08 14:05:00 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
#include <stdio.h>

int key_events(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		return close_window(fractal);
	if (keycode == 0x0063) // c
		return change_colors(fractal);
	//if (keycode == 0x0065) // e
	if (keycode == KEY_RIGHT) // e
		return shiftreal(fractal, '+');
	if (keycode == KEY_LEFT) // q
		return shiftreal(fractal, '-');
	if (keycode == KEY_UP) // w
		return shiftimaginary(fractal, '-');
	if (keycode == KEY_DOWN) // s
		return shiftimaginary(fractal, '+');
	if (keycode == 0x006a) //j
		return display_commands(fractal);
	if (keycode == 0x006b)
		return change_juliay(fractal);
	return 0;
}

int mouse_events(int button, int x, int y, t_fractal *fractal)
{
	if (button == 5 )
		return zoom_out(fractal);
	if (button == 4)
		return zoom_in(fractal, x, y);
	if (button == 1 && fractal->set == 1)
		return change_julias_shape(fractal, x, y);
	return 0;
}

int close_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
	return (0);
}

int change_juliax(t_fractal *fractal)
{
	fractal->current_point.real += 0.01;
	fractal_refresh(fractal);
	return 0;
}

int change_juliay(t_fractal *fractal)
{
	fractal->current_point.imaginary += 0.01;
	fractal_refresh(fractal);
	return 0;
}


int change_colors(t_fractal *fractal)
{
	//int colors[] = {0x0011FC92, 0x00119EFC, 0x00FCBE11, 0x00AB3434};
	fractal->colorset = fractal->colorset * 0.7 + 5;
	//fractal->colorset = fractal->colorset * 1.5 - 560;
	//fractal->colorset = fractal->colorset * 1.01 + 5;
	fractal_refresh(fractal);	
	return 0;
}
