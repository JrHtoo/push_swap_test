/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:59:53 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/08/30 09:24:00 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!big)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[j])
		{
			while (i + j < len && big[i + j] == little[j])
			{
				if (little[j + 1] == '\0')
					return ((char *)big + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	const char str1[30] = "Hello World! Goodbye! Hello";
// 	const char str2[10] = "World";
// 	char *c;
// 	c = ft_strnstr(str1, str2, 20);
// 	printf("%s\n", c);
// }