/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:46:39 by val               #+#    #+#             */
/*   Updated: 2023/11/20 22:47:42 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_atoui(const char *str);

int	ft_atoi(const char *str)
{
	if (!*str)
		return (0);
	while (ft_strchr(" \t\n\r\v\f", *str))
		str++;
	if (*str == '-')
	{
		str++;
		return (-ft_atoui(str));
	}
	if (*str == '+')
		str++;
	return (ft_atoui(str));
}

static unsigned int	ft_atoui(const char *str)
{
	int	output;

	output = 0;
	while (ft_isdigit(*str))
	{
		output = output * 10 + (*str - '0');
		str++;
	}
	return (output);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_atoi("\0"));
}
*/
