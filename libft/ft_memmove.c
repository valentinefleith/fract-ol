/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:03:51 by vafleith          #+#    #+#             */
/*   Updated: 2023/11/28 19:15:45 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memory areas may overlap.
 * If overlap at the beginning of src = no problem (memcpy)
 * If overlap at the end of src = need to copy backwards
 *
 * Problem occurs if dest > src and dest < src + n
 */

#include "libft.h"

static void	*ft_rev_cpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src == dest)
		return (dest);
	if (n)
	{
		if (dest > src && dest < src + n)
			return (ft_rev_cpy(dest, src, n));
		return (ft_memcpy(dest, src, n));
	}
	return (dest);
}

static void	*ft_rev_cpy(void *dest, const void *src, size_t n)
{
	char	*dest_bytes;
	char	*src_bytes;

	dest_bytes = (char *)dest;
	src_bytes = (char *)src;
	while (n)
	{
		dest_bytes[n - 1] = src_bytes[n - 1];
		n--;
	}
	return (dest);
}
