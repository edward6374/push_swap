/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:25:51 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/20 18:11:57 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_alg(t_stack *stack)
{
	if (stack->len_a == 1)
		return (1);
	else if (stack->len_a == 2)
		return (two_numbers(stack));
	else if (stack->len_a == 3)
		return (three_numbers(stack));
	else if (stack->len_a == 4)
		return (four_numbers(stack, 0));
	else if (stack->len_a == 5)
		return (five_numbers(stack));
	else if (stack->len_a <= 100)
		return (until_hundred(stack));
	else
		return (more_than_hundred(stack));
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	else
	{
		if (!check_args(argv))
			return (end_program(&stack, 1));
		if (!init_stack(&stack, argc, argv))
			return (end_program(&stack, 1));
	}
//	print_stack(&stack);
	if (!sort_alg(&stack))
		return (end_program(&stack, 1));
//	print_stack(&stack);
	end_program(&stack, 0);
	return (0);
}
