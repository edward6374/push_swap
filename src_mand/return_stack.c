/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:34:54 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/22 19:06:04 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_a(t_stack *stack)
{
	if (stack->supp_a[0] > stack->supp_a[1] && stack->len_a >= 2)
	{
		sa(stack);
		stack->moved = 0;
	}
}

void	check_other_conditions(t_stack *stack, int i)
{
	if ((stack->supp_b[i] == (stack->len_b - 1) && stack->moved == 0) ||
		(stack->supp_b[i] == stack->len_b && stack->moved == 1))
		rb(stack);
	else if ((stack->supp_b[stack->len_b - i - 1] == (stack->len_b - 1) &&
		stack->moved == 0) || (stack->supp_b[stack->len_b - i - 1] == stack->len_b &&
		stack->moved == 1))
		rrb(stack);
}

int	check_conditions(t_stack *stack, int i)
{
	if ((stack->supp_b[0] == (stack->len_b - 1) && stack->moved == 0) ||
		(stack->supp_b[0] == stack->len_b && stack->moved == 1))
	{
		pa(stack);
		return (0);
	}
	else if ((stack->supp_b[1] == (stack->len_b - 1) && stack->moved == 0) ||
		(stack->supp_b[1] == stack->len_b && stack->moved == 1))
	{
		rb(stack);
		pa(stack);
		return (0);
	}
	else 
		check_other_conditions(stack, i);
	if (stack->supp_b[0] == (stack->len_b - 2) && stack->moved == 0)
	{
		pa(stack);
		stack->moved = 1;
		return (1);
	}
	else
		return (1);
}

void	return_to_a(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->len_b > 0)
	{
		i = 0;
		while (i <= (stack->len_b / 2))
		{
			if (check_conditions(stack, i))
				i++;
			else
			{
				check_a(stack);
				break ;
			}
		}
	}
}
