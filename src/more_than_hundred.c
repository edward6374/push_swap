/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:57:56 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/23 19:55:44 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*int	second_check_a(t_stack *stack, int min, int max, int i)
{
	if (stack->supp_a[i] >= ((min + max) / 2) &&
		stack->supp_a[i] <= max)
	{
		ra(stack);
		return (1);
	}
	else if (stack->supp_a[stack->len_a - i - 1] >= ((min + max) / 2) &&
		stack->supp_a[stack->len_a - i - 1] <= max)
	{
		rra(stack);
		return (1);
	}
	return (0);
}
*/
void	check_near_a_more(t_stack *stack, int min, int max)
{
	int	i;

	i = 0;
	while (i < (stack->len_a / 2))
	{
		if (stack->supp_a[i] >= min &&
			stack->supp_a[i] <= max)
		{
			ra(stack);
			break ;
		}
		else if (stack->supp_a[stack->len_a - i - 1] >= min &&
			stack->supp_a[stack->len_a - i - 1] <= max)
		{
			rra(stack);
			break ;
		}
//		else if (second_check_a(stack, min, max, i))
//			break;
		i++;
	}
}

int	push_a_more(t_stack *stack, int min, int max)
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
		check_near_a_more(stack, min, max);
	return (0);
}

int	more_than_hundred(t_stack *stack)
{
	int	i;
	int	part;
	int	times;
	int	count;

	i = 0;
	times = 1;
	part = stack->len_a / 9;
	count = part * (times - 1);
	while (stack->len_a > 0)
	{
		if (i > (times * part))
		{
			times++;
			count = part * (times - 1);
		}
		i += push_a_more(stack, count, times * part);
	}
	return_to_a(stack);
	return (1);
}
