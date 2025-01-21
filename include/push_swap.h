/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:27:05 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/01/21 14:19:25 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_data
{
	int		pivot;
	int		size;
	int		nmoves;
	int		index_limit;
	bool	which;
}	t_data;

void	ft_parsing(t_list **list, int argc, char **argv);
void	ft_free_stack(t_list **list);
void	ft_free_splits(char **split);
void	ft_error_message(t_list **list, char *str);
int		check_sorted(t_list **stack);
int		is_duplicate(t_list **list, int numb);
int		ft_isnumber(char *numb);
int		find_max(t_list **stack);
int		find_min(t_list **stack);
int		get_distance(t_list **stack, int index);
void	simple_sort(t_list **stack_a, t_list **stack_b);
void	index_init(t_list **stack);
int		ft_largest_index(t_list *stack, int size);
void	main_sort(t_list **stack_a, t_list **stack_b);
void	tiny_sort(t_list **stack_a, t_list **stack_b, t_data data);

// swap instruction
void	swap_s(t_list **stack_a, t_list **stack_b);
void	swap_b(t_list **list);
void	swap_a(t_list **list);

// push instruction
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);

// rotate instruction
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_r(t_list **stack_a, t_list **stack_b);

// reverse rotate instruction
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_r(t_list **stack_a, t_list **stack_b);

#endif