/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:58:48 by vafleith          #+#    #+#             */
/*   Updated: 2023/11/23 09:14:41 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_strs;
	size_t	joined_length;

	joined_length = 1 + ft_strlen(s1) + ft_strlen(s2);
	joined_strs = malloc(joined_length * sizeof(char));
	if (joined_strs == NULL)
		return (NULL);
	ft_strlcpy(joined_strs, s1, ft_strlen(s1) + 1);
	ft_strlcat(joined_strs, s2, joined_length + 1);
	return (joined_strs);
}
/*
#include <stdio.h>

int	main(void)
{
	char hello[] = "salut ";
	char everyone[] = "a tous";
	char* joined = ft_strjoin(hello, everyone);
	printf("trying to join '%s' and '%s'\n", hello, everyone);
	printf("joined strings = '%s'\n", joined);
}
*/
