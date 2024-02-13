/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:13:20 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/13 17:36:20 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

double ft_atod(char *str)
{
	// en partant du principe que l'input est correct
	int is_neg = 0;
	if (*str == '-')
	{
		is_neg = 1;
		str++;
	}
		// do something
	double output;

	output = 0.0;
	while (*str && ft_isdigit(*str) && *str != '.')
	{
		output = output * 10 + (*str - '0');
		str++;
	}
	if (!*str)
		return output;
	str++;
	int x = 1;
	while (*str && ft_isdigit(*str))
	{
		output = output + (*str - '0') / pow(10, x);
		str++;
		x++;
	}
	if (is_neg)
		return -output;
	return output;
}
