/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:20:57 by vafleith          #+#    #+#             */
/*   Updated: 2023/12/01 22:10:43 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_length;

	if (len == 0 && (!haystack || !needle))
		return (NULL);
	needle_length = ft_strlen(needle);
	if (!needle_length)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i + needle_length <= len)
	{
		if (!ft_strncmp((char *)(haystack + i), needle, needle_length))
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*result;

	char haystack[30] = "abcdef";
	result = ft_strnstr(haystack, "ef", 5);
	if (result == NULL)
		printf("OK\n");
	else
	{
		printf("rip\n");
		printf("the function returned %s instead of null\n", result);
		}
}
*/
