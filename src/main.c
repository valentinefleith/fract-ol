/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:57:50 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/22 17:20:30 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (MALLOC_ERROR);

	//Creer une fenetre
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "test window");
	if (vars.win == NULL)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (MALLOC_ERROR);

	}
	draw_fractal(vars);
	
	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 4, 0, manage_events, &vars);
	mlx_key_hook(vars.win, manage_events, &vars);

	// Lancer la boucle d'evenements
	mlx_loop(vars.mlx);
}
