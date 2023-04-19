/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:26:09 by maroy             #+#    #+#             */
/*   Updated: 2023/04/19 14:51:57 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static int	count_word(char *s, char c)
{
	int	i;
	int	words;

	if (!s)
		return (0);
	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			words++;
		i++;
	}
	return (words);
}

static char	*split_by_delimiter(char *s, char c)
{
	char	*buf;

	while (*s == c)
		s++;
	buf = s;
	while (*buf && *buf != c)
		buf++;
	*buf = '\0';
	return (ft_strdup(s));
}

static char	**free_strs(char **strs, char *s)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
	free(s);
	return (NULL);
}

static char	**split_string(char **strs, char *s1, char c, int j)
{
	int		i;

	i = 0;
	while (i < j)
	{
		if (*s1 != c)
		{
			strs[i] = split_by_delimiter(s1, c);
			if (!strs[i])
				return (free_strs(strs, s1));
			s1 = s1 + ft_strlen(strs[i]);
			i++;
		}
		s1++;
	}
	strs[i] = NULL;
	free(strs);
	return (strs);
}

char	**ft_split(char *s, char c)
{
	int		words;
	char	**strs;
	char	*s1;

	s1 = ft_strdup(s);
	if (!s1)
		return (NULL);
	words = count_word(s, c);
	strs = (char **)malloc(sizeof(char *) * (words + 1));
	if (!strs)
		return (NULL);
	return (split_string(strs, s1, c, words));
}
