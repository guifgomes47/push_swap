/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:09:47 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/13 18:45:48 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_index_location(t_list *list, int i, int list_len)
{
	int	find;

	find = 0;
	while (find < list_len / 2)
	{
		if (list->index == i)
			return (1);
		list = list->next;
		find++;
	}
	return (0);
}

void	ft_sort2(t_list **list)
{
	int	head;
	int	next;

	head = (*list)->index;
	next = (*list)->next->index;
	if (head > next)
		ft_swap(list);
}

void	ft_sort3(t_list **list)
{
	int	head;
	int	next;
	int	next_next;

	head = (*list)->index;
	next = (*list)->next->index;
	next_next = (*list)->next->next->index;
	if (next < next_next && head > next_next)
		ft_rotate(list);
	if (head > next)
		ft_sort2(list);
	if (next > next_next)
	{
		ft_reverse_rotate(list);
		head = (*list)->index;
		next = (*list)->next->index;
		if (head > next)
			ft_sort2(list);
	}
}

void	ft_sort5(t_list **head_a, t_list **head_b, int list_len)
{
	int	i;
	int	head;

	i = 0;
	while (list_len > 3)
	{
		head = (*head_a)->index;
		if (ft_is_list_sorted(*head_a) && !(*head_b))
			return ;
		else if (ft_is_list_sorted(*head_a) && (*head_b))
			ft_push(head_a, head_b, 'a');
		else if (head == 0 || (list_len == 4 && head == 1 && *head_b))
		{
			ft_push(head_b, head_a, 'b');
			list_len--;
			i++;
		}
		else if (ft_index_location(*head_a, i, list_len))
			ft_rotate(head_a);
		else
			ft_reverse_rotate(head_a);
	}
	ft_sort3(head_a);
	while ((*head_a)->index && *head_b)
		ft_push(head_a, head_b, 'a');
}

void	ft_radix_sort(t_list **head_a, t_list **head_b, int list_len)
{
	int	move;
	int	bitcheck;

	move = 0;
	bitcheck = 0;
	while (!ft_is_list_sorted(*head_a))
	{
		while (move < list_len)
		{
			if ((((*head_a)->index >> bitcheck) & 1) == 1)
				ft_rotate(head_a);
			else
				ft_push(head_b, head_a, 'b');
			move++;
		}
		while (*head_b)
			ft_push(head_a, head_b, 'a');
		move = 0;
		bitcheck++;
	}
}
