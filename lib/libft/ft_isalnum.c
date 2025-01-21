/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:36:22 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/08/30 09:14:49 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z')
		|| (i >= '0' && i <= '9'))
		return (1);
	return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%d\n", ft_isalnum('3'));
// 	printf("%d\n", ft_isalnum('K'));
// 	printf("%d\n", ft_isalnum('l'));
// 	printf("%d\n", ft_isalnum('d')));
// }