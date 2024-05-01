/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42perpignan.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:58:29 by picarlie            #+#    #+#             */
/*   Updated: 2023/12/18 17:58:29 by picarlie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	//Basic checks of argv
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2) //eg ./push_swap "0 1 2 3"
		argv = ft_split(argv[1], ' ');
	//argv + 1 because I skip ./push_swap
	//argc == 2 is a flag to check if I used split, I have to free it if an error occured
	stack_init(&a, argv + 1, argc == 2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2) //very quick sort
			sa(&a); //sa(&a, false);
		else if (stack_len(a) == 3) //tiny sort if there are 3 numbers to sort
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	return (0);
}


/*
	TODO
	- stack_init
	- free_stack
	- split
	- stack_sorted
	- stack_len
	- tiny_sort
	- Commands (s, r, rr, p ) + algorithm
*/