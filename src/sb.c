/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:50:35 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/18 11:56:25 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sb(t_stack *stack)
{
	int	temp;

	if (stack->len_b >= 2)
	{
		temp = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = temp;
		ft_printf("sb\n");
	}
	else
	{
		ft_printf("SB Failed!\n");
		return (0);
	}
	return (1);
}
