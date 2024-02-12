/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:57:50 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/13 00:57:31 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_args(int argc, char **argv, t_fractal *fractal)
{
	if (argc < 2)
	{
		ft_printf("Il faut un nom de fractale en argument.\n");
		ft_printf("Arguments possibles :\n\t- mandelbrot\n\t- julia\n\t- ship\n");
		return (0);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")))
		fractal->set = 0;
	else if (!ft_strncmp(argv[1], "julia", ft_strlen("julia")))
		fractal->set = 1;
	else if (!ft_strncmp(argv[1], "ship", ft_strlen("ship")))
		fractal->set = 2;
	else
	{
		ft_printf("Arguments possibles :\n\t- mandelbrot\n\t- julia\n\t- ship\n");
		return (0);
	}
	return (1);
}

// handle error cases in a separate function too (use exit() ?)
int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!parse_args(argc, argv, &fractal))
		return (1);
	fractal.mlx = mlx_init();
	if (fractal.mlx == NULL)
		return (1);
	fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "Fract-ol vafleith");
	if (fractal.win == NULL)
	{
		mlx_destroy_display(fractal.mlx);
		free(fractal.mlx);
		return (1);
	}
	init_fractal(&fractal);
	init_hook(&fractal);
}
