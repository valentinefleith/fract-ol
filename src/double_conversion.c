/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:13:20 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/15 19:37:14 by vafleith         ###   ########.fr       */
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

static char *ft_strinsert(char *str, char c, int index)
{
	char *new_str = malloc(ft_strlen(str) + 2);
	if (new_str == NULL)
		return NULL;
	int src_index = 0;
	int dest_index = 0;

	while (str[src_index])
	{
		if (dest_index == index)
		{
			new_str[dest_index] = c;
			dest_index++;
		}
		new_str[dest_index] = str[src_index];
		src_index++;
		dest_index++;
	}
	new_str[dest_index] = '\0';
	return new_str;
}

static char *add_starting_zeros(char *str, int nb)
{
	char *new_str = malloc(1 + ft_strlen(str) + nb);
	if (new_str == NULL)
		return NULL;
	int i = 0;
	while (i < nb)
	{
		new_str[i] = '0';
		i++;
	}
	ft_strlcpy(new_str + i, str, ft_strlen(str) + 1);
	free(str);
	return new_str;
}

char *ft_dtoa(double n)
{
	int precision = 10000;
	int dot_index;
	char *conversion;
	char *output;
	int is_neg;
	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	n *= precision;
	conversion = ft_itoa(n);
	size_t conv_len = ft_strlen(conversion);
	if (conv_len < 5)
	{
		conversion = add_starting_zeros(conversion, 5 - conv_len);
		conv_len = 5;
	}
	dot_index = ft_strlen(conversion) - 4;
	output = ft_strinsert(conversion, '.', dot_index);
	if (is_neg)
		output = ft_strinsert(output, '-', 0); // /!\ LEAKS
	free(conversion);
	return output;
}
