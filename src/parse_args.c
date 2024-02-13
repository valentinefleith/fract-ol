/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:40:47 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/13 17:56:38 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int nb_is_valid(char *argv)
{
	int i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]) && argv[i] != '.' && argv[i] != '-')
			return 0;
		i++;
	}
	return 1;
}

static void parse_julias_param(char **argv, t_fractal *fractal)
{
	if (!nb_is_valid(argv[2]) || !nb_is_valid(argv[3]))
	{
		ft_printf("Wrong number input. We will keep default values.\n");
		return ;
	}
	fractal->current_point.real = ft_atod(argv[2]);
	fractal->current_point.imaginary = ft_atod(argv[3]);
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
	{
		fractal->set = 1;
		if (argc == 4)
			parse_julias_param(argv, fractal);
	}
	else if (!ft_strncmp(argv[1], "ship", ft_strlen("ship")))
		fractal->set = 2;
	else
	{
		ft_printf("Arguments possibles :\n\t- mandelbrot\n\t- julia\n\t- ship\n");
		return (0);
	}
	return (1);
}