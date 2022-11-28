/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:52:56 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/18 12:56:46 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss(t_stack *stack)
{
	if (!sa(stack) || !sb(stack))
	{
		ft_printf("SS Failed!\n");
		return (0);
	}
	ft_printf("ss\n");
	return (1);
}
