/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:25:51 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/28 20:56:09 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

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

int	check_stacks(t_stack *stack)
{
	(void)stack;
	return (0);
}

int	do_mov(char *line, t_stack *stack)
{
	(void)line;
	(void)stack;
	return (0);
}

int	main(int argc, char **argv)
{
	char	*line;
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
	line = get_next_line(0);
	while (line)
	{
		do_mov(line, &stack);
		line = get_next_line(0);
	}
	check_stacks(&stack);
	return (0);
}
