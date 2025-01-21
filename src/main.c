/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:06:07 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/01/16 15:05:09 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*temp;
	t_list	*tempb;

	if (argc == 1)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_parsing(stack_a, argc, argv);
	if (check_sorted(stack_a))
		exit(EXIT_SUCCESS);
	if (argc <= 6)
		simple_sort(stack_a, stack_b);
	else
		main_sort(stack_a, stack_b);
	temp = *stack_a;
	ft_printf("content    index    current_pos\n");
	while (temp)
	{
		ft_printf("%d            %d           %d\n", temp->content, temp->index, temp->current_pos);
		temp = temp->next;
	}
	tempb = *stack_b;
	ft_printf("content    index    current_pos\n");
	while (tempb)
	{
		ft_printf("%d            %d           %d\n", tempb->content, tempb->index, tempb->current_pos);
		tempb = tempb->next;
	}
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
