/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:25:15 by val               #+#    #+#             */
/*   Updated: 2023/11/08 09:59:18 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	for (int i = 0; i < 127; i++)
	{
		if (ft_isalnum(i) == isalnum(i))
			printf("OK\n");
		else
			printf("NOT OK\n char = %c\n ft_isalpha tells %i\n but isalpha tells
				%i\n", i, ft_isalnum(i), isalnum(i));
	}
}
*/
