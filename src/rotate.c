/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:35:57 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/01/16 12:07:47 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;
	tmp = head->next;
	while (tmp->next)
	{
		tmp->current_pos--;
		tmp = tmp->next;
	}
	tmp->current_pos--;
	head->next = NULL;
	head->current_pos = tmp->current_pos + 1;
	ft_lstlast(*stack)->next = head;
}

void	rotate_a(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_r(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
