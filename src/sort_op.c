/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:09:47 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/09 11:56:35 by guilhfer         ###   ########.fr       */
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

void	ft_reverse_rotate(t_list **head)
{
	t_list	*tail;

	tail = *head;
	while (tail->next)
		tail = tail->next;
	tail->next = *head;
	(*head)->prev = tail;
	*head = tail->prev;
	(*head)->next = NULL;
	tail->prev = NULL;
	while ((*head)->prev)
		*head = (*head)->prev;
	ft_printf("rra\n");
}

void	ft_rotate(t_list **head)
{
	t_list	*tail;

	tail = *head;
	while (tail->next)
		tail = tail->next;
	tail->next = *head;
	(*head)->prev = tail;
	*head = (*head)->next;
	(*head)->prev = NULL;
	tail->next->next = NULL;
	tail->prev = NULL;
	ft_printf("ra\n");
}

void	ft_swap(t_list **list)
{
	t_list	*node;
	t_list	*new_head;

	node = *list;
	new_head = (*list)->next;
	node->next = new_head->next;
	new_head->next = node;
	new_head->prev = NULL;
	node->prev = new_head;
	if (node->next)
		node->next->prev = node;
	*list = new_head;
	ft_printf("sa\n");
}

int	ft_sort3(t_list **list)
{
	int	sum;

	ft_print_list(*list);
	sum = (*list)->index + (*list)->next->index;
	ft_printf("SUM: %d\n", sum);
	if (sum == 2)
	{
		if ((*list)->index > (*list)->next->index)
			ft_rotate(list);
		else
		{
			ft_reverse_rotate(list);
			ft_swap(list);
		}
	}
	else
	{
		if ((*list)->index > (*list)->next->index)
		{
			ft_rotate(list);
			ft_swap(list);
		}
		else
			ft_reverse_rotate(list);
	}
	ft_print_list(*list);
	return (0);
}

int	ft_sort2(t_list **list)
{
	ft_print_list(*list);
	if (((*list)->index) > ((*list)->next->index))
		ft_swap(list);
	ft_print_list(*list);
	return (0);
}
