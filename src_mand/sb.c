/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:50:35 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/30 16:48:09 by vduchi           ###   ########.fr       */
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
		temp = stack->supp_b[0];
		stack->supp_b[0] = stack->supp_b[1];
		stack->supp_b[1] = temp;
		if (ft_printf("sb\n") == -1)
			return (0);
	}
	else
		return (0);
	return (1);
}
