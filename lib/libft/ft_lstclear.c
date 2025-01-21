/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:31:36 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/11/14 15:26:03 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*l;
	t_list	*temp;

	l = *lst;
	while (l)
	{
		temp = l -> next;
		(del)(l -> content);
		free(l);
		l = temp;
	}
	*lst = NULL;
}
