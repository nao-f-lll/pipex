/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:49:27 by nlyamani          #+#    #+#             */
/*   Updated: 2024/10/05 18:09:35 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char c)
{
	int	w_c;
	int	w_in;

	w_c = 0;
	w_in = 0;
	while (*s)
	{
		if (*s != c && w_in == 0)
		{
			w_in = 1;
			w_c++;
		}
		else if (*s == c)
			w_in = 0;
		s++;
	}
	return (w_c);
}

static void	ft_free(char **words, int words_i)
{
	while (words_i-- > 0)
		free(words[words_i]);
	free(words);
}

static int	find_word_end(const char *s, char c)
{
	int		w_ed;

	w_ed = 0;
	while (s[w_ed])
	{
		if (s[w_ed] == c)
			return (w_ed);
		w_ed++;
	}
	return (w_ed);
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	int		words_i;

	words_i = 0;
	if (!s)
		return (NULL);
	words = malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words[words_i] = ft_substr(s, 0, find_word_end(s, c));
			if (!words[words_i])
				return (ft_free(words, words_i), NULL);
			words_i++;
			s += find_word_end(s, c);
		}
	}
	words[words_i] = NULL;
	return (words);
}
