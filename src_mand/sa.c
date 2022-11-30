/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:35:17 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/30 16:47:49 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack)
{
	int	temp;

	if (stack->len_a >= 2)
	{
		temp = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = temp;
		temp = stack->supp_a[0];
		stack->supp_a[0] = stack->supp_a[1];
		stack->supp_a[1] = temp;
		if (ft_printf("sa\n") == -1)
			return (0);
	}
	else
		return (0);
	return (1);
}
