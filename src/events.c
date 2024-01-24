/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:46:58 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/24 09:31:34 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
#include <stdio.h>

int manage_events(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		return close_window(fractal);
	if (keycode == 0x0063) // c
		return change_colors(fractal);
	if (keycode == 0x0065) // e
		return shiftreal(fractal, '+');
	if (keycode == 0x0071) // q
		return shiftreal(fractal, '-');
	if (keycode == 0x0077) // w
		return shiftimaginary(fractal, '-');
	if (keycode == 0x0073) // s
		return shiftimaginary(fractal, '+');
	if (keycode == 0x0070) // p
		return zoom_in(fractal);
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

int zoom_in(t_fractal *fractal)
{
	fractal->zoom *= 0.9;
	fractal_refresh(fractal);
	return 0;
}

int shiftreal(t_fractal *fractal, char direction)
{
	if (direction == '+')
		fractal->shiftx += 0.1;
	else 
		fractal->shiftx -= 0.1;
	fractal_refresh(fractal);
	return 0;
}

int shiftimaginary(t_fractal *fractal, char direction)
{
	if (direction == '+')
		fractal->shifty += 0.1;
	else 
		fractal->shifty -= 0.1;
	fractal_refresh(fractal);
	return 0;
}

int change_colors(t_fractal *fractal)
{
	//int colors[] = {0x0011FC92, 0x00119EFC, 0x00FCBE11};
	//int i = 0;
	if (fractal->colorset == 0x00119EFC)
		fractal->colorset = 0x00FCBE11;
	else if (fractal->colorset == 0x00FCBE11)
		fractal->colorset = 0x0011FC92;
	else if (fractal->colorset == 0x0011FC92)
		fractal->colorset = 0x00119EFC;

	fractal_refresh(fractal);	
	return 0;
}
