/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:32:45 by vafleith          #+#    #+#             */
/*   Updated: 2024/03/16 00:03:55 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	change_precision(t_fractal *fractal, int keycode)
{
	if (keycode == KEY_P)
	{
		if (fractal->max_iterations < MAX_ITERATIONS)
			fractal->max_iterations += 5;
	}
	if (keycode == KEY_M)
	{
		if (fractal->max_iterations > MIN_ITERATIONS)
			fractal->max_iterations -= 5;
	}
	fractal_refresh(fractal);
	return (0);
}

int	handle_lock(t_fractal *fractal)
{
	if (fractal->lock)
		fractal->lock = 0;
	else
		fractal->lock = 1;
	return (0);
}

int	handle_help(t_fractal *fractal)
{
	if (fractal->help == 0)
	{
		fractal->help = 1;
		return (display_commands(fractal));
	}
	fractal->help = 0;
	fractal_refresh(fractal);
	return (0);
}

int	change_fractal(t_fractal *fractal)
{
	if (fractal->set == 4)
		fractal->set = 0;
	else
		fractal->set++;
	fractal_refresh(fractal);
	return (0);
}

int	handle_rgb(t_fractal *fractal, int keycode)
{
	if (keycode == KEY_R)
		fractal->red += 0.1;
	else if (keycode == KEY_B)
		fractal->blue += 0.1;
	else
		fractal->green += 0.1;
	fractal_refresh(fractal);
	return (0);
}
