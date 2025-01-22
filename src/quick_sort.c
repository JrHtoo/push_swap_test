/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:10:11 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/01/22 16:47:17 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	select_pivot(t_list **stack_a, int size)
{
	int		i;
	int		sum;
	t_list	*tmp;

	i = 0;
	sum = 0;
	tmp = (*stack_a);
	while (i < size && tmp)
	{
		sum += tmp->index;
		tmp = tmp->next;
		i++;
	}
	tmp = (*stack_a);
	while (tmp->next && tmp->index != (sum / i))
		tmp = tmp->next;
	return (tmp->content);
}

static void	push_pivot(t_list **stack_a, t_list **stack_b, t_data *data, int size)
{
	int	i;

	i = 0;
	printf("pushing pivot started\n");
	while (i < size)
	{
		if ((*stack_a)->content == data->pivot)
			break ;
		rotate_a(stack_a);
		i++;
	}
	push_b(stack_a, stack_b);
	while (i-- > 0)
		reverse_rotate_a(stack_a);
	printf("pushing pivot ended\n");
}

static void	partition_a(t_list **stack_a, t_list **stack_b, t_data data, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if ((*stack_a)->content < data.pivot)
		{
			push_b(stack_a, stack_b);
			data.size++;
		}
		else
			rotate_a(stack_a);
	}
	while (i-- > 0)
		reverse_rotate_a(stack_a);
	size = size - data.size;
	push_pivot(stack_a, stack_b, &data, size);
}

static void	partition(t_list **stack_a, t_list **stack_b, t_data *data, int size)
{
	data->pivot = select_pivot(stack_a, size);
	data->size = 0;
	printf("Pivot   ===> %d\n", data->pivot);
	if (data->which && (*stack_a))
		partition_a(stack_a, stack_b, *data, size);
}

// static void	quick_sort(t_list **stack_a, t_list **stack_b, t_data data)
// {
// 	int	temp1;
// 	int	temp2;

// 	if (data.size <= 3)
// 	{
// 		printf("tiny_sort\n");
// 		tiny_sort(stack_a, stack_b, data);
// 		return ;
// 	}
// 	temp1 = data.size;
// 	temp2 = data.size - (data.size / 2);
// 	temp1 = data.size - temp2;
// 	data.size = temp1;
// 	partition(stack_a, stack_b, data);
// 	data.size = temp2;
// 	partition(stack_a, stack_b, data);
// 	if (data.which)
// 		data.which = false;
// 	else
// 		data.which = true;
// 	data.size = temp1;
// 	quick_sort(stack_a, stack_b, data);
// 	data.size = temp2;
// 	quick_sort(stack_a, stack_b, data);
// }

void	push_back_to_A(t_list **stack_a, t_list **stack_b, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		push_a(stack_a, stack_b);
		i++;
	}
}

static void	quick_sort(t_list **stack_a, t_list **stack_b, t_data data, int size)
{
	if (size <= 3)
	{
		printf("tiny_sort\n");
		tiny_sort(stack_a, stack_b, data, size);
		return ;
	}
	partition(stack_a, stack_b, &data, size);
	push_back_to_A(stack_a, stack_b, size);
	partition(stack_a, stack_b, &data, size / 2);
	// quick_sort(stack_a, stack_b, data, size / 2);
	// partition(stack_a, stack_b, &data, size);
	// push_back_to_A(stack_a, stack_b, size);
	// quick_sort(stack_a, stack_b, data, size - (size / 2));
}

void	main_sort(t_list **stack_a, t_list **stack_b)
{
	t_data	data;

	data.size = ft_lstsize(*stack_a);
	data.index_limit = ft_largest_index(*stack_a, data.size);
	data.which = true;
	data.size = ft_lstsize(*stack_a);
	printf("Quick_sort\n");
	quick_sort(stack_a, stack_b, data, data.size);
	// while ((*stack_b))
	// 	push_a(stack_a, stack_b);
}
