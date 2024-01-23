/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:46:58 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/23 17:23:30 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fract-ol.h"

int manage_events(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		return close_window(fractal);
	//if (keycode == 0x0063)
		//return change_color(vars);
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

//int change_colors(t_fractal *fractal)
//{
//	int colors[] = {0x0011FC92, 0x00119EFC, 0x00FCBE11};
//	int i = 0;
//	//while 
//	return i;
//}
