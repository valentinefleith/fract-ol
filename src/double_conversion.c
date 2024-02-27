/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:13:20 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/27 19:11:22 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_get_dot_pos(char *str)
{
	double	pos;

	pos = 0;
	while (*str)
	{
		if (*str == '.')
			return (pos);
		pos++;
		str++;
	}
	return (-1);
}

double	ft_atod(char *str)
{
	int		is_neg;
	double	output;
	double	dot_pos;

	dot_pos = ft_get_dot_pos(str);
	if (dot_pos < 0)
		return (ft_atoi(str));
	dot_pos = ft_strlen(str) - dot_pos - 1;
	is_neg = 0;
	if (*str == '-')
	{
		is_neg = 1;
		str++;
	}
	output = 0.0;
	while (*str && (ft_isdigit(*str) || *str == '.'))
	{
		if (*str != '.')
			output = output * 10 + (*str - '0');
		str++;
	}
	if (is_neg)
		return (-output / pow(10, dot_pos));
	return (output / pow(10, dot_pos));
}

static char	*ft_strinsert_andfree(char *str, char c, int index)
{
	char	*new_str;
	int		src_index;
	int		dest_index;

	new_str = malloc(ft_strlen(str) + 2);
	if (new_str == NULL)
		return (NULL);
	src_index = 0;
	dest_index = 0;
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
	free(str);
	return (new_str);
}

static char	*add_starting_zeros_andfree(char *str, int nb)
{
	char	*new_str;
	int		i;

	new_str = malloc(1 + ft_strlen(str) + nb);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		new_str[i] = '0';
		i++;
	}
	ft_strlcpy(new_str + i, str, ft_strlen(str) + 1);
	free(str);
	return (new_str);
}

char	*ft_dtoa(double n)
{
	int		precision;
	char	*conversion;
	char	*output;
	int		is_neg;
	size_t	conv_len;

	precision = 10000;
	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	n *= precision;
	conversion = ft_itoa(n);
	conv_len = ft_strlen(conversion);
	if (conv_len < 5)
	{
		conversion = add_starting_zeros_andfree(conversion, 5 - conv_len);
		conv_len = 5;
	}
	output = ft_strinsert_andfree(conversion, '.', ft_strlen(conversion) - 4);
	if (is_neg)
		output = ft_strinsert_andfree(output, '-', 0);
	return (output);
}
