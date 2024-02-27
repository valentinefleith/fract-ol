/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:57:50 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/27 19:10:09 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!parse_args(argc, argv, &fractal))
		return (2);
	fractal.mlx = mlx_init();
	if (fractal.mlx == NULL)
		return (1);
	fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT,
			"Fract-ol vafleith");
	if (fractal.win == NULL)
	{
		mlx_destroy_display(fractal.mlx);
		free(fractal.mlx);
		return (1);
	}
	init_fractal(&fractal);
	init_hook(&fractal);
}
