/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:41:17 by vafleith          #+#    #+#             */
/*   Updated: 2023/11/18 17:44:17 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*bytes;

	i = 0;
	bytes = (unsigned char *)s;
	while (i < n)
	{
		if (bytes[i] == (unsigned char)c)
			return (bytes + i);
		i++;
	}
	return (NULL);
}
