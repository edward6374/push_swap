/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:31:38 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/29 11:48:23 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	loop_ra(t_stack *stack, int *new, int *new_supp, int *temp)
{
	int	i;

	i = -1;
	while (++i < (stack->len_a - 1))
	{
		new[i] = stack->stack_a[i + 1];
		new_supp[i] = stack->supp_a[i + 1];
	}
	new[i] = temp[0];
	new_supp[i] = temp[1];
	free(stack->stack_a);
	free(stack->supp_a);
	stack->stack_a = new;
	stack->supp_a = new_supp;
	return (1);
}

int	ra(t_stack *stack)
{
	int	temp[2];
	int	*new;
	int	*new_supp;

	if (stack->len_a < 1)
		return (0);
	temp[0] = stack->stack_a[0];
	temp[1] = stack->supp_a[0];
	new = (int *)malloc(sizeof(int) * stack->len_a);
	if (!new)
		return (0);
	new_supp = (int *)malloc(sizeof(int) * stack->len_a);
	if (!new_supp)
	{
		free(new);
		return (0);
	}
	return (loop_ra(stack, new, new_supp, temp));
}
