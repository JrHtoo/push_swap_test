/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:55:46 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/08/30 09:19:55 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*cpy;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len && s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char	src[20] = "Hello World!";
// 	char	*dest1 = ft_strdup(src);
// 	char	*dest2 = strdup(src);
// 	printf("%s\n", dest1);
// 	printf("%s\n", dest2);
// }