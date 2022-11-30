/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:51:24 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/30 16:47:12 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	loop_rrb(t_stack *stack, int *new, int *new_supp, int *temp)
{
	int	i;

	i = 0;
	new[0] = temp[0];
	new_supp[0] = temp[1];
	while (++i < stack->len_b)
	{
		new[i] = stack->stack_b[i - 1];
		new_supp[i] = stack->supp_b[i - 1];
	}
	free(stack->stack_b);
	free(stack->supp_b);
	stack->stack_b = new;
	stack->supp_b = new_supp;
	if (ft_printf("rrb\n") == -1)
		return (0);
	return (1);
}

int	rrb(t_stack *stack)
{
	int	temp[2];
	int	*new;
	int	*new_supp;

	if (stack->len_b < 1)
		return (0);
	temp[0] = stack->stack_b[stack->len_b - 1];
	temp[1] = stack->supp_b[stack->len_b - 1];
	new = (int *)malloc(sizeof(int) * stack->len_b);
	if (!new)
		return (0);
	new_supp = (int *)malloc(sizeof(int) * stack->len_b);
	if (!new_supp)
	{
		free(new);
		return (0);
	}
	return (loop_rrb(stack, new, new_supp, temp));
}
