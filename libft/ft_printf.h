/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:27:19 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/29 15:57:11 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

int	ft_printf(const char *format, ...);

int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_unsigned(unsigned int nb);
int	ft_print_nbr(int nb);
int	ft_print_nbr_base(unsigned long long nb, char *base, char format);

#endif
