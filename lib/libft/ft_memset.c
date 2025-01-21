/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:12:42 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/08/30 13:13:40 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char str[50] = " I am a student!@#$";
// 	printf("%s\n", str);

// 	memset(str + 5, '.', 30*sizeof(char));
// 	printf("%s\n",str);

// 	char str1[50] = " I am a student!@#$";
// 	printf("%s\n", str1);

// 	ft_memset(str1 + 5, '.', 50*sizeof(char));
// 	printf("%s\n",str1);
// 	return (0);
// }