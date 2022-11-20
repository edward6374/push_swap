/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   until_five_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:11:18 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/20 13:55:27 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	two_numbers(t_stack *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack);
	return (1);
}

int	three_numbers(t_stack *stack)
{
	int	check;

	check = 0;
	while (!check)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			sa(stack);
		if (stack->stack_a[1] > stack->stack_a[2])
			rra(stack);
		if (stack->stack_a[0] < stack->stack_a[1] &&
			stack->stack_a[1] < stack->stack_a[2])
			check++;
	}
	return (1);
}

int	four_numbers(t_stack *stack, int n)
{
	int	check;

	check = 0;
	while (!check)
	{
		if (stack->supp_a[0] != n)
		{
			rra(stack);
			continue ;
		}
		check++;
	}
	pb(stack);
	three_numbers(stack);
	pa(stack);
	return (1);
}

int	five_numbers(t_stack *stack)
{
	int	check;

	check = 0;
	while (!check)
	{
		if (stack->supp_a[0] != 0)
		{
			rra(stack);
			continue ;
		}
		check++;
	}
	pb(stack);
	four_numbers(stack, 1);
	pa(stack);
	return (1);
}
