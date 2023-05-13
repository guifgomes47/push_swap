/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:28:02 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/13 16:29:54 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_list_index(t_list *list, int list_len)
{
	int	new_index;
	int	min;

	new_index = 0;
	min = MAX_INT;
	while (new_index < list_len)
	{
		while (list)
		{
			if (list->value < min && list->index == -1)
				min = list->value;
			if (!list->next)
				break ;
			list = list->next;
		}
		while (list)
		{
			if (list->value == min)
				list->index = new_index++;
			if (!list->prev)
				break ;
			list = list->prev;
		}
		min = MAX_INT;
	}
}

int	ft_is_list_sorted(t_list *list)
{
	int	max;

	max = MIN_INT;
	while (list)
	{
		if (list->value < max)
			return (0);
		max = list->value;
		list = list->next;
	}
	return (1);
}

int	ft_list_len(t_list *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

//Add head_b
void	ft_sort_check(t_list **head_a, t_list **head_b)
{
	int	list_len;

	list_len = ft_list_len(*head_a);
	if (ft_is_list_sorted(*head_a))
		return ;
	ft_list_index(*head_a, list_len);
	if (list_len == 2)
	{
		ft_sort2(head_a);
		return ;
	}
	if (list_len == 3)
	{
		ft_sort3(head_a);
		return ;
	}
	if (list_len == 4 || list_len == 5)
		ft_sort5(head_a, head_b, list_len);
	else
		ft_radix_sort(head_a, head_b, list_len);
	while ((*head_a)->prev)
		*head_a = (*head_a)->prev;
}
