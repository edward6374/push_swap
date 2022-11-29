/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:35:17 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/29 11:51:30 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	}
	else
		return (0);
	return (1);
}
