/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:57:50 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/23 17:25:09 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

//void fractal_refresh(t_fr)

int main(void)
{
	t_fractal fractal;

	fractal.mlx = mlx_init();
	if (fractal.mlx == NULL)
		return (MALLOC_ERROR);

	//Creer une fenetre
	fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "test window");
	if (fractal.win == NULL)
	{
		mlx_destroy_display(fractal.mlx);
		free(fractal.mlx);
		return (MALLOC_ERROR);

	}
	draw_fractal(fractal);
	
	//mlx_mouse_hook(fractal.win, mouse_hook, &vars);
	mlx_hook(fractal.win, 4, 0, manage_events, &fractal);
	mlx_key_hook(fractal.win, manage_events, &fractal);

	// Lancer la boucle d'evenements
	mlx_loop(fractal.mlx);
}
