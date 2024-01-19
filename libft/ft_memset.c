/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:27:20 by vafleith          #+#    #+#             */
/*   Updated: 2023/09/15 22:07:34 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*bytes;

	i = 0;
	bytes = s;
	while (i < n)
	{
		bytes[i] = c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 64

int	main(void)
{
	char	str[BUFFER_SIZE];

	strcpy(str, "hello salut ca va");
	printf("%s\n", str);
	ft_memset(str, 'a', 5);
	printf("%s\n", str);
}
*/
