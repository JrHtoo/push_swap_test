/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:56:45 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/01/16 12:13:50 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	tmp->current_pos++;
	*stack = (*stack)->next;
	(*stack)->current_pos--;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	swap_a(t_list **list)
{
	swap(list);
	ft_printf("sa\n");
}

void	swap_b(t_list **list)
{
	swap(list);
	ft_printf("sb\n");
}

void	swap_s(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
