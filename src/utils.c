/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:59:01 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/18 11:55:14 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	ft_printf("Stack A\n");
	while (++i < stack->len_a)
		ft_printf("Number %d: %d\n", i + 1, stack->stack_a[i]);
	ft_printf("\nStack B\n");
	while (++j < stack->len_b)
		ft_printf("Number %d: %d\n", j + 1, stack->stack_b[j]);
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

	i = 0;
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
	while (i < count - 1)
	{
		stack->stack_a[i] = my_atoi(argv[i + 1], 1);
		stack->supp_a[i] = my_atoi(argv[i + 1], 1);
		i++;
	}
	if (!ss(stack))
		return (0);
	return (1);
}
