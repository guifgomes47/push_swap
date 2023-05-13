/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:19:11 by guilhfer          #+#    #+#             */
/*   Updated: 2023/04/29 23:36:55 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_has_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] && argv[i + 1])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j])
		{
			if (argv[i][0] == '-' && j == 0)
				j++;
			if (ft_isdigit(argv[i][j]))
				j++;
			else
				return (0);
		}
		if (ft_atol(argv[i]) > MAX_INT || ft_atol(argv[i]) <= MIN_INT)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2)
		exit(0);
	if (argc == 2 && ft_is_number(argv))
	{
		exit(0);
	}
	if (ft_has_duplicates(argv))
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (!ft_is_number(argv))
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (0);
}
