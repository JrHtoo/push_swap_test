/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:13:29 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/11/18 13:17:12 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_splits(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_free_stack(t_list **list)
{
	t_list	*tmp;
	t_list	*current;

	current = *list;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(list);
}

void	ft_error_message(t_list **list, char *str)
{
	ft_printf("%s\n", str);
	ft_free_stack(list);
	exit(EXIT_FAILURE);
}
