/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:26:11 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/08/30 09:16:00 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	chr;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char str[] = "tripouille";
// 	char ch = 't';
// 	char *dest;
// 	char *dest1;
// 	dest = ft_memchr(str, ch + 256, strlen(str));
// 	printf("%s\n", dest);
// 	dest1 = ft_memchr(str, ch +256, strlen(str));
// 	printf("%s\n", dest1);
// 	return (0);
// }