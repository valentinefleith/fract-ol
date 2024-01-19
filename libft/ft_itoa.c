/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:20:16 by vafleith          #+#    #+#             */
/*   Updated: 2023/11/13 22:47:06 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_str_size(int n);
char	*ft_uitoa(unsigned int n, char *dest, int size);

char	*ft_itoa(int n)
{
	int				size_of_new_str;
	char			*result;
	unsigned int	absolute_value;

	size_of_new_str = ft_find_str_size(n);
	result = malloc(1 + size_of_new_str * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		*result = '-';
		result++;
		absolute_value = -n;
		result = ft_uitoa(absolute_value, result, size_of_new_str - 1);
		return (result - 1);
	}
	else
		absolute_value = n;
	return (ft_uitoa(absolute_value, result, size_of_new_str));
}

char	*ft_uitoa(unsigned int n, char *dest, int size)
{
	int	index;

	index = size - 1;
	while (index >= 0)
	{
		dest[index] = (n % 10 + '0');
		n = n / 10;
		index--;
	}
	dest[size] = '\0';
	return (dest);
}

int	ft_find_str_size(int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}
/*
#include <stdio.h>

int	main(void)
{
	int	number;

	number = 0;
	printf("%s\n", ft_itoa(number));
}
*/
