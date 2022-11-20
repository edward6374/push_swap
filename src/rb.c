/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:53:50 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/18 20:05:59 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	loop_rb(t_stack *stack, int *new, int *new_supp, int *temp)
{
	int	i;

	i = -1;
	while (++i < (stack->len_b - 1))
	{
		new[i] = stack->stack_b[i + 1];
		new_supp[i] = stack->supp_b[i + 1];
	}
	new[i] = temp[0];
	new_supp[i] = temp[1];
	free(stack->stack_b);
	free(stack->supp_b);
	stack->stack_b = new;
	stack->supp_b = new_supp;
	ft_printf("rb\n");
	return (1);
}

int	rb(t_stack *stack)
{
	int	i;
	int	temp[2];
	int	*new;
	int	*new_supp;

	i = -1;
	if (stack->len_b < 1)
	{
		ft_printf("RB Failed!\n");
		return (0);
	}
	temp[0] = stack->stack_b[0];
	temp[1] = stack->supp_b[0];
	new = (int *)malloc(sizeof(int) * stack->len_b);
	if (!new)
		return (0);
	new_supp = (int *)malloc(sizeof(int) * stack->len_b);
	if (!new_supp)
	{
		free(new);
		return (0);
	}
	return (loop_rb(stack, new, new_supp, temp));
}
