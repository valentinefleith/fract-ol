/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:45:07 by vafleith          #+#    #+#             */
/*   Updated: 2023/12/01 22:38:12 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_length;
	size_t	dest_length;
	size_t	count;

	src_length = ft_strlen(src);
	if (((!dest) || (!src)) && size == 0)
		return (src_length);
	dest_length = ft_strlen(dest);
	if (size < dest_length || size < 1)
		return (src_length + size);
	count = 0;
	while (*dest)
	{
		dest++;
		count++;
	}
	while (*src && count < size - 1)
	{
		*dest = *src;
		src++;
		dest++;
		count++;
	}
	*dest = '\0';
	return (src_length + dest_length);
}
