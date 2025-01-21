/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:54:24 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/11/21 11:19:11 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_isnumber(char *numb)
{
	int	i;

	i = 0;
	if (numb[i] == '-' || numb[i] == '+')
		i++;
	while (numb[i])
	{
		if (ft_isdigit(numb[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_list **list, int numb)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		if (temp->content == numb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_parsing(t_list **list, int argc, char **argv)
{
	int		i;
	int		j;
	char	**splits;

	i = 1;
	while (i < argc)
	{
		j = 0;
		splits = ft_split(argv[i], ' ');
		while (splits[j])
		{
			if (ft_isnumber(splits[j]) == 0)
				ft_error_message(list, "Error");
			if (is_duplicate(list, ft_atoi(splits[j])) == 0)
				ft_error_message(list, "Error");
			ft_lstadd_back(list, ft_lstnew(ft_atoi(splits[j++])));
		}
		ft_free_splits(splits);
		i++;
	}
	index_init(list);
}
