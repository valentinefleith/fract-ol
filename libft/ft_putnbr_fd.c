/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:14:42 by vafleith          #+#    #+#             */
/*   Updated: 2023/10/05 19:22:34 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_unsigned_fd(unsigned int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	absolute_value;

	absolute_value = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		absolute_value = -n;
	}
	ft_put_unsigned_fd(absolute_value, fd);
}

void	ft_put_unsigned_fd(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_put_unsigned_fd(n / 10, fd);
		ft_put_unsigned_fd(n % 10, fd);
	}
}

/*
int	main(void)
{
	ft_putnbr_fd(-1542, 1);
}
*/
