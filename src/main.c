/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:54:22 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/04 23:02:20 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_stack_a(char **argv)
{
	t_list	*head_a;
	int		i;

	// t_list	*head_b;
	i = 1;
	head_a = NULL;
	// head_b = NULL;
	while (argv[i])
	{
		if (head_a == NULL)
		{
			head_a = ft_new_node(ft_atoi(argv[i++]));
			if (!head_a)
				return (1);
		}
		head_a->next = ft_new_node(ft_atoi(argv[i++]));
		if (!head_a->next)
			return (ft_free_list(head_a));
		ft_append(&head_a, head_a->next);
		head_a = head_a->next;
	}
	while (head_a->prev)
		head_a = head_a->prev;
	//Add head_b
	ft_sort_check(&head_a);
	return (0);
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	ft_stack_a(argv);
	return (0);
}
