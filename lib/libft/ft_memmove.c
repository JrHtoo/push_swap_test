/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:40:29 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/08/30 09:28:07 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dest > src)
	{
		while (n)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	dest[40] = "Hailogenrrrrrr";
// 	char	src[10] = "Yayyyy";

// 	printf("%s\n", dest);
// 	memmove(dest+3, src, sizeof(src) + 1);
// 	printf("%s\n", dest);

// 	// char	dest1[20] = "Hydrogenrrrrrr";

// 	// printf("%s\n", dest1);
// 	// ft_memmove(dest, src, 2);
// 	// printf("%s\n", dest1);
// }