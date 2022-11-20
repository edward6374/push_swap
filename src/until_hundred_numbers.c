/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   until_hundred_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:46:30 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/20 20:44:16 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	if_check(t_stack *stack, int min, int count)
{
	if ((stack->supp_a[0] >= min &&
		stack->supp_a[0] <= (count / 2)))
	{
		ft_printf("1\n");
		pb(stack);
		rb(stack);
		return (1);
	}
	else if (stack->supp_a[0] > (count / 2) &&
		stack->supp_a[0] <= count)
	{
		ft_printf("2\n");
		pb(stack);
//		rb(stack);
		return (1);
	}
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
//		print_stack(stack);
		if (i >= (times * part))
		{
			times++;
			count = part * (times - 1);
			if (times == 3)
				exit(0);
		}
		if (if_check(stack, count, times * part))
		{
			ft_printf("Here\n");
			i++;
			count++;
		}
//		if (i > (times * part))
//			times++;
//		if (stack->supp_a[0] >= ((times - 1) * part) &&
//			stack->supp_a[0] <= (times * part))
//		{
//			pb(stack);
//			i++;
//		}
		else if (stack->supp_a[1] == i || stack->supp_a[2] == i)
			ra(stack);
		else
			rra(stack);
		ft_printf("Count: %d\nMin: %d\nSupp: %d\n", times * part, count, stack->supp_a[0]);
	}
	ft_printf("End\n");
	return (1);
}
