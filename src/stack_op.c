/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:13:42 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/13 17:40:06 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	ft_rotate(t_list **list)
{
	t_list	*new_head;

	new_head = *list;
	new_head->next->prev = NULL;
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->next = new_head;
	new_head->prev = *list;
	new_head->next = NULL;
	while ((*list)->prev)
		*list = (*list)->prev;
	ft_printf("ra\n");
}

void	ft_push(t_list **dest, t_list **source, char c)
{
	t_list	*node;

	node = *source;
	*source = node->next;
	if (*source)
		(*source)->prev = NULL;
	ft_insert_front(dest, node);
	if (c == 'a')
		ft_printf("pa\n");
	if (c == 'b')
		ft_printf("pb\n");
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
