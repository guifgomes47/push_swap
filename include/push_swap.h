/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:46:57 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/04 23:37:31 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_list
{
	struct s_list	*prev;
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

int					check_args(int argc, char **argv);
void				ft_sort_check(t_list **head_a);
t_list				*ft_new_node(int value);
void				ft_append(t_list **list, t_list *new);
int					ft_free_list(t_list *list);
int					ft_sort2(t_list **list);
int					ft_sort3(t_list **list);

void				ft_print_list(t_list *list);
#endif