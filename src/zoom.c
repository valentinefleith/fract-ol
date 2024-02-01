/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:04:57 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/01 11:59:37 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int zoom_in(t_fractal *fractal)
{
	fractal->zoom *= 0.95;
	if (fractal->max_iterations < MAX_ITERATIONS)
		fractal->max_iterations++;
	fractal_refresh(fractal);
	return 0;
}

int zoom_out(t_fractal *fractal)
{
	fractal->zoom /= 0.85;
	fractal->max_iterations--;
	fractal_refresh(fractal);
	return 0;
}

int zoom_and_shift(t_fractal *fractal, int x, int y)
{
	t_pixel px;
	t_complex mouse_pos;

	px.x = x;
	px.y = y;
	fractal->zoom *= 0.9;
	
	fractal->shiftx += (rescale_pixel(px, fractal).real * fractal->zoom);
	fractal->shifty += (rescale_pixel(px, fractal).imaginary * fractal->zoom);
	fractal_refresh(fractal);
	return 0;
}
