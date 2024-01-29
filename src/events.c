/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:46:58 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/29 16:05:32 by vafleith         ###   ########.fr       */
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
	if (keycode == 0x006d) // m
		return zoom_out(fractal);
	if (keycode == 0x006a) //j
		return change_julia(fractal);
	return 0;
}

int mouse_events(int button, int x, int y, t_fractal *fractal)
{
	//(void)x;
	//(void)y;
	if (button == 5 )
		return zoom_out(fractal);
	if (button == 4)
		return zoom_in(fractal);
	if (button == 1)
	{
		ft_printf("mouse position : x:%i y:%i\n", x, y);
	}
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

int change_julia(t_fractal *fractal)
{
	fractal->current_point.real += 0.01;
	fractal->current_point.imaginary += 0.1;
	fractal_refresh(fractal);
	return 0;
}


int shiftreal(t_fractal *fractal, char direction)
{
	if (direction == '+')
		fractal->shiftx += (0.2 * fractal->zoom);
	else 
		fractal->shiftx -= (0.2 * fractal->zoom);
	fractal_refresh(fractal);
	return 0;
}

int shiftimaginary(t_fractal *fractal, char direction)
{
	if (direction == '-')
		fractal->shifty += (0.1 * fractal->zoom);
	else 
		fractal->shifty -= (0.1 * fractal->zoom);
	fractal_refresh(fractal);
	return 0;
}

int change_colors(t_fractal *fractal)
{
	//int colors[] = {0x0011FC92, 0x00119EFC, 0x00FCBE11, 0x00AB3434};
	//fractal->colorset = fractal->colorset * 0.7 + 5;
	fractal->colorset = fractal->colorset * 1.01 + 5;
	fractal_refresh(fractal);	
	return 0;
}
