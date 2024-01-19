/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:15:37 by vafleith          #+#    #+#             */
/*   Updated: 2023/11/21 17:40:00 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	n;

	n = count * size;
	if (n && (size != n / count))
		return (NULL);
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n);
	return (ptr);
}
