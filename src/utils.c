/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:50:53 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/11/21 13:54:45 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_distance(t_list **stack, int number)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (number == head->content)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	find_min(t_list **stack)
{
	int		min;
	t_list	*temp;

	temp = *stack;
	min = temp->content;
	while (temp)
	{
		if (min > temp->content)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}

int	find_max(t_list **stack)
{
	int		max;
	t_list	*temp;

	temp = *stack;
	max = temp->content;
	while (temp)
	{
		if (max < temp->content)
			max = temp->content;
		temp = temp->next;
	}
	return (max);
}


static t_list	*get_next_min(t_list **stack)
{
	int		has_min;
	t_list	*head;
	t_list	*min;

	has_min = 0;
	head = *stack;
	min = NULL;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min
					|| head->content < min->content))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_init(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}
