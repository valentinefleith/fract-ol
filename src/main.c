/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:57:50 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/13 00:43:29 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	fractal_refresh(t_fractal *fractal)
{
	t_img	new_img;

	mlx_destroy_image(fractal->mlx, fractal->img.img);
	new_img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	// TODO : verify that malloc worked
	// /!\ LEAKS (free everything)
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel,
			&new_img.line_length, &new_img.endian);
	fractal->img = new_img;
	calculate_and_put_pixels(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, new_img.img, 0, 0);
	display_standard(fractal);
}

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

// TODO : create new function for init everything separately
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
	// mlx_mouse_hook(fractal.win, mouse_hook, &vars);
	// mlx_hook(fractal.win, 4, 0, key_events, &fractal);
	// mlx_hook(fractal.win, 4, 0, mouse_events, &fractal);
	mlx_mouse_hook(fractal.win, mouse_events, &fractal);
	mlx_key_hook(fractal.win, key_events, &fractal);
	mlx_hook(fractal.win, 17, 0, exit_program, &fractal);
	//mlx_mouse_get_pos(fractal.mlx, fractal.win, &x, &y);
	//printf("%i, %i\n", x, y);
	if (fractal.set == 1)
		mlx_hook(fractal.win, 6, 1L << 6, mouse_move, &fractal);
	// Lancer la boucle d'evenements
	mlx_loop(fractal.mlx);
}
