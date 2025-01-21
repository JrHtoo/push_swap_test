/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:28:37 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/08/28 11:28:33 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if ((dest == src) || n == 0)
		return (dest);
	if (!dest || !src)
		return (0);
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char src[20] = "I am a student";
// 	char dest[20];
// 	memcpy(dest, src, sizeof(src));
// 	printf("%s\n", dest);
// 	char dest1[20];
// 	ft_memcpy(dest1, src, sizeof(src));
// 	printf("%s\n", dest);
// }