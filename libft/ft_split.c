/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:34:40 by vafleith          #+#    #+#             */
/*   Updated: 2023/11/21 22:33:15 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *str, char c);
static size_t	ft_strlen_custom(char *s, char c);
static void		ft_free_all_substrs(char **strs, int count);
static char		**ft_fill_substrs(char **strs, char *s, int nb_words, char c);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		nb_words;

	if (!s)
		return (NULL);
	nb_words = ft_count_words(s, c);
	strs = ft_calloc(nb_words + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	strs = ft_fill_substrs(strs, (char *)s, nb_words, c);
	return (strs);
}

static char	**ft_fill_substrs(char **strs, char *s, int nb_words, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < nb_words)
	{
		if (s[j] != c)
		{
			strs[i] = ft_substr(s, j, ft_strlen_custom(s + j, c));
			i++;
			if (!strs)
			{
				ft_free_all_substrs(strs, nb_words);
				return (NULL);
			}
			while (s[j] && s[j] != c)
				j++;
		}
		j++;
	}
	strs[i] = 0;
	return (strs);
}

static int	ft_count_words(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

static size_t	ft_strlen_custom(char *s, char c)
{
	size_t	size;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

static void	ft_free_all_substrs(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**result;
	char	sep;
	int		word_count;

	char test[] = "*******hello*world****hjflhf**********";
	sep = '*';
	word_count = ft_count_words(test, sep);
	result = ft_split(test, sep);
	printf("%i words :\n", word_count);
	for (int i = 0; result[i]; i++)
	{
		printf("%s\n", result[i]);
	}
}
*/
