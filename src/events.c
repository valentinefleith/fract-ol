/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:46:58 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/22 18:20:20 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fract-ol.h"

int manage_events(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		return close_window(vars);
	//if (keycode == 0x0063)
		//return change_color(vars);
	return 0;
}

int close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int change_colors(t_vars *vars)
{
	int colors[] = {0x0011FC92, 0x00119EFC, 0x00FCBE11};
	int i = 0;
	//while 
	return i;
}
