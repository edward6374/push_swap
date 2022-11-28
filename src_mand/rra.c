/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:24:31 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/21 19:38:50 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	loop_rra(t_stack *stack, int *new, int *new_supp, int *temp)
{
	int	i;

	i = 0;
	new[0] = temp[0];
	new_supp[0] = temp[1];
	while (++i < stack->len_a)
	{
		new[i] = stack->stack_a[i - 1];
		new_supp[i] = stack->supp_a[i - 1];
	}
	free(stack->stack_a);
	free(stack->supp_a);
	stack->stack_a = new;
	stack->supp_a = new_supp;
	ft_printf("rra\n");
	return (1);
}

int	rra(t_stack *stack)
{
	int	temp[2];
	int	*new;
	int	*new_supp;

	if (stack->len_a < 1)
	{
		ft_printf("RRA Failed!\n");
		return (0);
	}
	temp[0] = stack->stack_a[stack->len_a - 1];
	temp[1] = stack->supp_a[stack->len_a - 1];
	new = (int *)malloc(sizeof(int) * stack->len_a);
	if (!new)
		return (0);
	new_supp = (int *)malloc(sizeof(int) * stack->len_a);
	if (!new_supp)
	{
		free(new);
		return (0);
	}
	return (loop_rra(stack, new, new_supp, temp));
}
