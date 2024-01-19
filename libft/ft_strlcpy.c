/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:16:00 by vafleith          #+#    #+#             */
/*   Updated: 2023/11/16 17:09:32 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#define BUFFER_SIZE 64

int	main(void)
{
	char	dest[BUFFER_SIZE];

	char src[] = "hello";
	printf("length of string we tried to copy : %li\n", ft_strlcpy(dest, src,
			BUFFER_SIZE));
	printf("destination : %s\n", dest);
}
*/
