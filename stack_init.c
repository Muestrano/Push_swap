/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:33:57 by marvin            #+#    #+#             */
/*   Updated: 2024/04/30 20:33:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Converts str to long int
	Also checks for overflows
	Multiple signs are not allowed (checked before)
*/
long	ft_atol(const char *str)
{
	long	nb;
	int		sign;
	int		i;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

void	stack_init(t_stack_node **a, char **argv, bool argc_2)
{
	long	nb;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, argc_2);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error_free(a, argv, argc_2);
		if (error_repetition(*a, (int)nb))
			error_free(a, argv, argc_2);
		append_node(a, (int)nb);
		i++;
	}
	if (argc_2)
		free_matrix(argv);
}

/*
	TODO
	error_syntax (if letters, multiple signs...)
	error_free (free if error)
	error_repetition (checks for repetition)
	apprend_node
	free_matrix (ie the split in the main for argv if argv == 2)
*/