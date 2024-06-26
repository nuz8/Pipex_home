/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:56:13 by pamatya           #+#    #+#             */
/*   Updated: 2024/06/26 21:47:22 by pamatya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char			**ft_parse(char const *s, char c);
static size_t	f_word_count(char const *str, char c);
static void		f_word_lengths(char const *str, char c, size_t *wordlens);
static void		f_write(char **split, char const *s, char c);

char	**ft_parse(char const *s, char c)
{
	char	**split;
	size_t	wcount;
	size_t	*wordlens;
	size_t	i;

	wcount = f_word_count(s, c);
	wordlens = (size_t *)malloc(wcount * sizeof(size_t));
	if (!wordlens)
		return (NULL);
	split = (char **)malloc((wcount + 1) * sizeof(char *));
	if (!split)
		return (free(wordlens), NULL);
	f_word_lengths(s, c, wordlens);
	i = 0;
	while (i < wcount)
	{
		split[i] = (char *)malloc((wordlens[i] + 1) * sizeof(char));
		if (!split[i])
			return (free(wordlens), ft_free2D(split), NULL);
		i++;
	}
	split[wcount] = NULL;
	f_write(split, s, c);
	free(wordlens);
	return (split);
}	// return (split[wcount] = NULL, f_write(split, s, c), free(wordlens), split);

static size_t	f_word_count(char const *str, char c)
{
	char	*s;
	size_t	wcount;
	int		quote;

	wcount = 0;
	quote = 0;
	s = (char *)str;
	while (*s)
	{
		if (*s != c)
		{
			wcount++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (wcount);
}

static void	f_word_lengths(char const *str, char c, size_t *wordlens)
{
	char	*s;
	size_t	length;
	size_t	i;

	i = 0;
	s = (char *)str;
	while (*s)
	{
		length = 0;
		if (*s != c)
		{
			while (*s && *s != c)
			{
				length++;
				s++;
			}
			wordlens[i] = length;
			i++;
		}
		else
			s++;
	}
}

static void	f_write(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	length;

	i = 0;
	while (*s)
	{
		j = 0;
		length = 0;
		if (*s != c)
		{
			while (*s && *s != c)
				split[i][j++] = *s++;
			split[i][j] = '\0';
			i++;
		}
		else
			s++;
	}
}