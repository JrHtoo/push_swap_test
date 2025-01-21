/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:36:42 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/11/14 15:29:40 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new_list;
	t_list	*save;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew(f(lst -> content));
	if (!new_list)
		return (0);
	save = new_list;
	lst = lst -> next;
	while (lst)
	{
		new_list -> next = ft_lstnew(f(lst -> content));
		if (!new_list -> next)
		{
			ft_lstclear(&new_list, *del);
			return (NULL);
		}
		new_list = new_list -> next;
		lst = lst -> next;
	}
	new_list -> next = NULL;
	return (save);
}

// #include <stdio.h>
// #include <string.h>

// void    ft_del(void *content)
// {
// 	free(content);
// }

// void	ft_printresult(t_list *list)
// {
// 	int	i;

// 	i = 0;
// 	while (list)
// 	{
// 		printf("list %d -----> %s\n", i + 1, (char *)list -> content);
// 		list = list -> next;
// 		i++;
// 	}
// }

// void	*ftt_toupper(void *c)
// {
// 	unsigned char	*str;
// 	int				i;

// 	i = 0;
// 	str = (unsigned char *)c;
// 	while (str[i])
// 	{
// 		if (str[i] >= 97 && str[i] <= 122)
// 			str[i] = str[i] - 32;
// 		i++;
// 	}
// 	return ((void *)str);
// }

// int main(void)
// {
// 	t_list	*e1;
// 	t_list	*e2;
// 	t_list	*e3;
// 	t_list	*e4;
// 	t_list	*list;
// 	char		*str = strdup("lorem");
// 	char		*str2 = strdup("ipsum");
// 	char		*str3 = strdup("dolor");
// 	char		*str4 = strdup("sit");

// 	e1 = ft_lstnew(str);
// 	e2 = ft_lstnew(str2);
// 	e3 = ft_lstnew(str3);
// 	e4 = ft_lstnew(str4);
// 	e1 -> next = e2;
// 	e2 -> next = e3;
// 	e3 -> next = e4;

// 	printf("The original list\n");
// 	ft_printresult(e1);
// 	list = ft_lstmap(e1, &ftt_toupper, &ft_del);
// 	printf("\n\nThe new list\n");
// 	ft_printresult(list);
// }