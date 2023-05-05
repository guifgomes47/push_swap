/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:09:47 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/04 23:38:31 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print_list(t_list *list)
{
	ft_printf("LISTA A:\n");
	ft_printf("---------\n");
	while (list)
	{
		ft_printf("Value: %d\n", list->value);
		ft_printf("Index: %d\n", list->index);
		if (!list->next)
			break ;
		list = list->next;
	}
}

void	ft_swap(t_list **list)
{
	t_list	*node_1;
	t_list	*node_2;

	node_1 = *list;
	node_2 = (*list)->next;
	node_1->next = node_2->next;
	node_2->next = node_1;
	node_2->prev = NULL;
	node_1->prev = node_2;
	if (node_1->next)
		node_1->next->prev = node_1;
	*list = node_2;
	ft_printf("sa\n");
}

int	ft_sort3(t_list **list)
{
	ft_print_list(*list);
	// if (list)
	return (0);
}

int	ft_sort2(t_list **list)
{
	ft_print_list(*list);
	if (((*list)->value) > ((*list)->next->value))
		ft_swap(list);
	ft_print_list(*list);
	return (0);
}
