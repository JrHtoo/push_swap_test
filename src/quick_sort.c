/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:10:11 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/01/21 16:43:05 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	select_pivot(t_list **stack_a, t_list **stack_b, t_data data)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (data.which == false)
	{
		
	}
	else
	{
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp->index == data.size / 2)
				break ;
			tmp = tmp->next;
		}
	}
	return (tmp->content);
}

static void	push_pivot(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	i;

	i = 0;
	data->nmoves = 0;
	printf("pushing pivot started\n");
	if (data->which == true)
	{
		while (i < data->size && ft_lstsize(*stack_a) > 5)
		{
			if ((*stack_a)->index >= data->index_limit)
				rotate_a(stack_a);
			else if ((*stack_a)->content != data->pivot)
			{
				push_b(stack_a, stack_b);
				rotate_b(stack_b);
				data->nmoves++;
			}
			else
				break ;
			i++;
		}
		push_b(stack_a, stack_b);
	}
	else
	{
		while (i < data->size && ft_lstsize(*stack_b))
		{
			if ((*stack_b)->index >= data->index_limit)
				rotate_b(stack_b);
			else if ((*stack_b)->content != data->pivot)
			{
				push_a(stack_a, stack_b);
				rotate_a(stack_a);
				data->nmoves++;
			}
			else
				break ;
			i++;
		}
		push_a(stack_a, stack_b);
	}
	printf("pushing pivot ended\n");
}

static void	partition_a(t_list **stack_a, t_list **stack_b, t_data data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i++ < data.size)
	{
		if ((*stack_a)->content < data.pivot)
		{
			push_b(stack_a, stack_b);
			j++;
		}
		else
			rotate_a(stack_a);
	}
	data.size = data.size - j;
	printf("Pivot   ===> %d\n", data.pivot);
	push_pivot(stack_a, stack_b, &data);
	while (data.nmoves > 0)
	{
		reverse_rotate_b(stack_b);
		data.nmoves--;
	}
	i = 0;
	while (i++ <= data.size && ft_lstsize(*stack_a) > 5)
	{
		if ((*stack_a)->index <= data.index_limit)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
}

static void	partition_b(t_list **stack_a, t_list **stack_b, t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < data.size)
	{
		if ((*stack_b)->content < data.pivot)
		{
			push_a(stack_a, stack_b);
			j++;
		}
		else
			rotate_b(stack_b);
	}
	data.size = data.size - j;
	printf("Pivot   ===> %d\n", data.pivot);
	push_pivot(stack_a, stack_b, &data);
	while (data.nmoves > 0)
	{
		reverse_rotate_a(stack_a);
		data.nmoves--;
	}
	i = 0;
	while (i++ <= data.size && ft_lstsize(*stack_b))
	{
		if ((*stack_b)->index <= data.index_limit)
			push_a(stack_a, stack_b);
		else
			rotate_b(stack_b);
	}
}

static void	partition(t_list **stack_a, t_list **stack_b, t_data data)
{
	data.pivot = select_pivot(stack_a, stack_b, data);
	if (data.which)
		partition_a(stack_a, stack_b, data);
	else
		partition_b(stack_a, stack_b, data);
}

static void	quick_sort(t_list **stack_a, t_list **stack_b, t_data data)
{
	int	temp1;
	int	temp2;

	if (data.size <= 3)
	{
		printf("tiny_sort\n");
		tiny_sort(stack_a, stack_b, data);
		return ;
	}
	temp1 = data.size;
	temp2 = data.size - (data.size / 2);
	temp1 = data.size - temp2;
	data.size = temp1;
	partition(stack_a, stack_b, data);
	data.size = temp2;
	partition(stack_a, stack_b, data);
	if (data.which)
		data.which = false;
	else
		data.which = true;
	data.size = temp1;
	quick_sort(stack_a, stack_b, data);
	data.size = temp2;
	quick_sort(stack_a, stack_b, data);
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
// }

void	main_sort(t_list **stack_a, t_list **stack_b)
{
	t_data	data;

	data.size = ft_lstsize(*stack_a);
	data.index_limit = ft_largest_index(*stack_a, data.size) - 5 ;
	data.which = true;
	data.pivot = select_pivot(stack_a, stack_b, data);
	partition(stack_a, stack_b, data);
	printf("Simple sort\n");
	simple_sort(stack_a, stack_b);
	data.which = false;
	data.size = ft_lstsize(*stack_b);
	printf("Quick_sort\n");
	quick_sort(stack_a, stack_b, data);
	// while ((*stack_b))
	// 	push_a(stack_a, stack_b);
}
