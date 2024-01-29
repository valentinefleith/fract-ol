/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:54:08 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/29 15:53:44 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(char format, va_list arguments);

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		count;

	if (!format)
		return (0);
	va_start(arguments, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_print_arg(*format, arguments);
		}
		else
			count += ft_print_char(*format);
		format++;
	}
	va_end(arguments);
	return (count);
}

int	ft_print_arg(char format, va_list arguments)
{
	if (format == 'c')
		return (ft_print_char(va_arg(arguments, int)));
	if (format == '%')
		return (ft_print_char('%'));
	if (format == 's')
		return (ft_print_str(va_arg(arguments, char *)));
	if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(arguments, int)));
	if (format == 'u')
		return (ft_print_unsigned(va_arg(arguments, unsigned int)));
	if (format == 'x')
		return (ft_print_nbr_base(va_arg(arguments, unsigned int), LOWER_HEX,
				format));
	if (format == 'X')
		return (ft_print_nbr_base(va_arg(arguments, unsigned int), UPPER_HEX,
				format));
	if (format == 'p')
		return (ft_print_nbr_base((unsigned long long)va_arg(arguments, void *),
				LOWER_HEX, format));
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int	ret_val;
	int	real_val;

	unsigned int test;
	
	test = 2147483648;
	ret_val = ft_printf("Hello %u\n", test);
	real_val = printf("Hello %u\n", test);
	if (ret_val == real_val)
		printf("return value OK :)\n");
	else
		printf("wrong return value. Expected %i, got %i\n", real_val, ret_val);
}
*/
