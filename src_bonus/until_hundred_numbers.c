/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   until_hundred_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:46:30 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/28 20:08:04 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_near_a(t_stack *stack, int min, int max)
{
	int	i;

	i = 0;
	while (i < stack->len_a)
	{
		if (stack->supp_a[i] >= min &&
			stack->supp_a[i] <= max &&
			i <= stack->len_a)
		{
			ra(stack);
			break ;
		}
		else if (stack->supp_a[i] >= min &&
			stack->supp_a[i] <= max &&
			i > stack->len_a)
		{
			rra(stack);
			break ;
		}
		i++;
	}
}

int	push_a(t_stack *stack, int min, int max)
{
	if ((stack->supp_a[0] >= min &&
		stack->supp_a[0] <= ((min + max) / 2)))
	{
		pb(stack);
		rb(stack);
		return (1);
	}
	else if (stack->supp_a[0] > ((min + max) / 2) &&
		stack->supp_a[0] <= max)
	{
		pb(stack);
		return (1);
	}
	else
		check_near_a(stack, min, max);
	return (0);
}

int	until_hundred(t_stack *stack)
{
	int	i;
	int	part;
	int	times;
	int	count;

	i = 0;
	times = 1;
	part = stack->len_a / 3;
	count = part * (times - 1);
	while (stack->len_a > 0)
	{
		if (i > (times * part))
		{
			times++;
			count = part * (times - 1);
		}
		i += push_a(stack, count, times * part);
	}
	return_to_a(stack);
	return (1);
}
