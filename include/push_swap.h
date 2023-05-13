/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:46:57 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/13 17:51:20 by guilhfer         ###   ########.fr       */
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

//|MAIN FUNCTIONS:
//|file: main.c
//|file: check_args.c
int					check_args(int argc, char **argv);
//|file: node_op.c
t_list				*ft_new_node(int value);
void				ft_insert_front(t_list **list, t_list *new);
void				ft_insert_end(t_list **list, t_list *new);
int					ft_free_list(t_list *list);
//|file: sort_check.c
void				ft_sort_check(t_list **head_a, t_list **head_b);
int					ft_is_list_sorted(t_list *list);
//|file: sort_op.c
void				ft_sort2(t_list **list);
void				ft_sort3(t_list **list);
void				ft_sort5(t_list **head_a, t_list **head_b, int list_len);
void				ft_radix_sort(t_list **head_a, t_list **head_b,
						int list_len);
//|file: stack_op.c
void				ft_push(t_list **dest, t_list **source, char c);
void				ft_swap(t_list **list);
void				ft_rotate(t_list **list);
void				ft_reverse_rotate(t_list **head);

#endif