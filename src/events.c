/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:46:58 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/21 15:35:13 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <inttypes.h>
#include <stdio.h>

int	key_events(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ESC)
		return (exit_program(fractal));
	if (keycode == KEY_C)
		return (change_colors(fractal));
	if (keycode == KEY_P || keycode == KEY_M)
		return (change_precision(fractal, keycode));
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT || keycode == KEY_UP
		|| keycode == KEY_DOWN)
		return (handle_shift(fractal, keycode));
	if (keycode == KEY_R)
	{
		init_struct(fractal, fractal->img);
		fractal_refresh(fractal);
	}
	if (keycode == KEY_B || keycode == KEY_D)
		return (change_brightness(fractal, keycode));
	if (keycode == KEY_H)
		return (handle_help(fractal));
	if (keycode == KEY_L)
		return (handle_lock(fractal));
	if (keycode == KEY_F)
		return (change_fractal(fractal));
	return (0);
}

int	mouse_events(int button, int x, int y, t_fractal *fractal)
{
	if (button == 5)
		return (zoom_out(fractal));
	if (button == 4)
		return (zoom_in(fractal, x, y));
	if (button == 1 && fractal->set == 1)
		return (change_julias_shape(x, y, fractal));
	return (0);
}

int	mouse_move(int x, int y, t_fractal *fractal)
{
	if (fractal->lock)
		return (1);
	change_julias_shape(x, y, fractal);
	return (0);
}
