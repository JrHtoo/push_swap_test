/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:40:26 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/11/14 13:18:49 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countletter(char const *s, char c, int pos)
{
	int	count;

	count = 0;
	while (s[pos] != c && s[pos])
	{
		count++;
		pos++;
	}
	return (count);
}

static int	ft_wordcount(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*word_generator(char const *s, char c, int pos)
{
	int		len;
	int		i;
	char	*word;

	len = ft_countletter(s, c, pos);
	word = (char *)malloc(len + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (s[pos + i] != c && s[pos + i])
	{
		word[i] = s[pos + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		pos;
	int		size;
	char	**lst;

	if (!s)
		return (NULL);
	size = ft_wordcount(s, c);
	lst = (char **)malloc(sizeof(char *) * (size + 1));
	if (lst == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	while (s[pos])
	{
		if (s[pos] != c && s[pos])
		{
			lst[i] = word_generator(s, c, pos);
			pos = pos + ft_countletter(s, c, pos) - 1;
			i++;
		}
		pos++;
	}
	lst[i] = 0;
	return (lst);
}
