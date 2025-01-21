/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:04:12 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/08/30 13:17:31 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char str[30] = "I am a stuent";
// 	printf("%s\n", str);
// 	ft_bzero(str, 1*sizeof(char));
// 	printf("%s\n", str);

// 	char str1[30] = "I am a stuent";
// 	printf("%s\n", str1);
// 	ft_bzero(str1, 1*sizeof(char));
// 	printf("%s\n", str1);
// }