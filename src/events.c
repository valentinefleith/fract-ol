/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:46:58 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/23 18:48:49 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int manage_events(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		return close_window(fractal);
	if (keycode == 0x0063)
		return change_colors(fractal);
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

int change_colors(t_fractal *fractal)
{
	//int colors[] = {0x0011FC92, 0x00119EFC, 0x00FCBE11};
	//int i = 0;
	if (fractal->colorset == 0x00119EFC)
		fractal->colorset = 0x00FCBE11;
	else if (fractal->colorset == 0x00FCBE11)
		fractal->colorset = 0x00119EFC;

	fractal_refresh(fractal);	
	return 0;
}
