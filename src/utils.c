/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:59:01 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/20 16:51:28 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_supp(t_stack *stack)
{
	int	i;
	int	min;
	int	lim;
	int	idx;
	int	last;

	lim = -1;
	last = -2147483648;
	while (++lim < stack->len_a)
	{
		i = -1;
		idx = 0;
		min = 2147483647;
		while (++i < stack->len_a)
		{
			if (stack->stack_a[i] <= min && stack->stack_a[i] > last)
			{
				min = stack->stack_a[i];
				idx = i;
			}
		}
		last = min;
		stack->supp_a[idx] = lim;
	}
}

void	print_stack(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	ft_printf("\nStack A\n");
	while (++i < stack->len_a)
		ft_printf("Number %d: %d, Relative: %d\n", i + 1, stack->stack_a[i], stack->supp_a[i]);
	ft_printf("\nStack B\n\n");
	while (++j < stack->len_b)
		ft_printf("Number %d: %d, Relative: %d\n", j + 1, stack->stack_b[j], stack->supp_b[j]);
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	end_program(t_stack *stack, int i)
{
	if (i)
		print_error();
	if (stack->supp_a)
		free(stack->supp_a);
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->supp_b)
		free(stack->supp_b);
	if (stack->stack_b)
		free(stack->stack_b);
	return (0);
}

int	init_stack(t_stack *stack, int count, char **argv)
{
	int	i;

	i = -1;
	stack->len_a = count - 1;
	stack->len_b = 0;
	stack->supp_a = (int *)malloc(sizeof(int) * (count - 1));
	if (!stack->supp_a)
		return (end_program(stack, 1));
	stack->stack_a = (int *)malloc(sizeof(int) * (count - 1));
	if (!stack->stack_a)
		return (end_program(stack, 1));
	stack->supp_b = NULL;
	stack->stack_b = NULL;
	while (++i < count - 1)
		stack->stack_a[i] = my_atoi(argv[i + 1], 1);
	fill_supp(stack);
	return (1);
}
