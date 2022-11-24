/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:25:51 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/24 14:54:02 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(char **argv, int count)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * count);
	while (i < (count - 1))
	{
		arr[i] = my_atoi(argv[i + 1], 1);
		i++;
	}
	i = 0;
	while (i < (count - 2))
	{
		if (arr[i] > arr[i + 1])
		{
			free(arr);
			return (0);
		}
		i++;
	}
	free(arr);
	return (1);
}

void	set_stack(t_stack *stack)
{
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->supp_a = NULL;
	stack->supp_b = NULL;
}

int	sort_alg(t_stack *stack)
{
	if (stack->len_a == 1)
		return (1);
	else if (stack->len_a == 2)
		return (two_numbers(stack));
	else if (stack->len_a == 3)
		return (three_numbers(stack));
	else if (stack->len_a == 4)
		return (four_numbers(stack, 0));
	else if (stack->len_a == 5)
		return (five_numbers(stack));
	else if (stack->len_a <= 101)
		return (until_hundred(stack));
	else
		return (more_than_hundred(stack));
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	set_stack(&stack);
	if (argc == 1)
		return (0);
	if (!ft_strncmp(argv[1], "", 1))
		return (print_error());
	else
	{
		if (!check_args(argv))
			return (end_program(&stack, 1));
		if (is_ordered(argv, argc))
			return (0);
		if (!init_stack(&stack, argc, argv))
			return (end_program(&stack, 1));
	}
	print_stack(&stack);
	if (!sort_alg(&stack))
		return (end_program(&stack, 1));
	end_program(&stack, 0);
	return (0);
}
