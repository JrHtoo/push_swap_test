/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:16:05 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/11/14 13:19:32 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	chr;

	if (!s)
		return (NULL);
	i = 0;
	chr = (char)c;
	while (s[i])
	{
		if (chr == s[i])
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == chr)
		return ((char *)(s + i));
	return (0);
}
