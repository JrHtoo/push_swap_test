/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:36:43 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/01/16 12:11:07 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp_from;
	t_list	*tmp_to;

	if (!*stack_from)
		return ;
	tmp_from = (*stack_from)->next;
	(*stack_from)->next = *stack_to;
	*stack_to = *stack_from;
	tmp_to = *stack_to;
	tmp_to->current_pos = 0;
	tmp_to = tmp_to->next;
	while (tmp_to)
	{
		tmp_to->current_pos++;
		tmp_to = tmp_to->next;
	}
	*stack_from = tmp_from;
	while (tmp_from)
	{
		tmp_from->current_pos--;
		tmp_from = tmp_from -> next;
	}
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
