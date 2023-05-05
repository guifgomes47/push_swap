/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:19:39 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/03 02:08:30 by guilhfer         ###   ########.fr       */
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

// void	ft_pop(t_list **list)
// {
// 	t_list	new;

// 	new = list;
// 	if (!list)
// 		return ;
// 	(*list)->next = new;
// }

void	ft_append(t_list **list, t_list *new)
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
