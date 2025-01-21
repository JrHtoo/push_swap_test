/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:07:41 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/08/30 09:24:56 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (NULL);
	str = 0;
	if (s1 != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, &s1[i], j - i + 1);
		str[j - i] = '\0';
	}
	return (str);
}

// #include <stdio.h>

// int main(void)
// {
// 	char s1[40] = "abcbcbc123ac41abcbcbabbbbbb";
// 	char s2[7]= "abc";

// 	printf("%s\n", ft_strtrim(s1, s2));
// }