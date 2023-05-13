/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:19:39 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/13 18:55:14 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_new_node(int value)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->index = -1;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	ft_insert_front(t_list **list, t_list *new)
{
	if (!new)
		return ;
	if (*list == NULL)
	{
		*list = new;
		(*list)->next = NULL;
		return ;
	}
	(*list)->prev = new;
	new->next = *list;
	*list = new;
}

void	ft_insert_end(t_list **list, t_list *new)
{
	if (!list || !new)
		return ;
	new->prev = *list;
	(*list)->next = new;
}

int	ft_free_list(t_list *list)
{
	t_list	*temp;
	t_list	*next;

	if (!list)
		return (0);
	temp = list;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	list = NULL;
	return (0);
}
