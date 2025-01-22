/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_another_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:55:49 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/01/22 16:22:40 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_largest_index(t_list *stack, int size)
{
	int		i;
	int		index;
	t_list	*tmp;

	i = 0;
	index = -1;
	tmp = stack;
	while (tmp && i < size)
	{
		if (index < tmp->index)
			index = tmp->index;
		i++;
		tmp = tmp->next;
	}
	return (index);
}

static void	sort_2(t_list **stack_a, t_list **stack_b, t_data data)
{
	if (data.which)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a);
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
	}
	else
	{
		if ((*stack_b)->content < (*stack_b)->next->content)
			swap_b(stack_a);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
}

static int	conditioning(t_list **stack)
{
	int		i1;
	int		i2;
	int		i3;

	i1 = (*stack)->content;
	i2 = (*stack)->next->content;
	i3 = (*stack)->next->next->content;
	if (i2 < i1 && i2 < i3)
		return (0);
	else if (i3 < i1 && i3 < i2)
		return (1);
	return (-1);
}

static void	sort_3(t_list **stack_a, t_list **stack_b, t_data data)
{
	int		check;
	bool	rotate;

	rotate = false;
	if (data.which)
	{
		check = conditioning(stack_a);
		if (check == 0)
			swap_a(stack_a);
		else if (check == 1)
		{
			rotate_a(stack_a);
			swap_a(stack_a);
			rotate = true;
		}
		push_b(stack_a, stack_b);
		if (rotate)
			rotate_a(stack_a);
		sort_2(stack_a, stack_b, data);
	}
	else
	{
		check = conditioning(stack_b);
		if (check == -1)
			swap_b(stack_b);
		else if (check == 1)
		{
			rotate_b(stack_b);
			swap_b(stack_b);
			rotate = true;
		}
		push_a(stack_a, stack_b);
		if (rotate)
			rotate_b(stack_b);
		sort_2(stack_a, stack_b, data);
	}
}

void	tiny_sort(t_list **stack_a, t_list **stack_b, t_data data, int size)
{
	if (size == 2)
		sort_2(stack_a, stack_b, data);
	else if (size == 3)
		sort_3(stack_a, stack_b, data);
}
