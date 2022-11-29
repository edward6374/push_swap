/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:25:51 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/29 12:56:09 by vduchi           ###   ########.fr       */
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

int	check_stacks(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->len_a <= 0 || stack->len_b > 0)
		return (0);
	while (i < (stack->len_a - 1))
	{
		if (stack->supp_a[i] > stack->supp_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	do_mov(char *line, t_stack *stack)
{
	int	res;

	if (!ft_strncmp(line, "ra\n", 3))
		res = ra(stack);
	else if (!ft_strncmp(line, "rb\n", 3))
		res = rb(stack);
	else if (!ft_strncmp(line, "sa\n", 3))
		res = sa(stack);
	else if (!ft_strncmp(line, "sb\n", 3))
		res = sb(stack);
	else if (!ft_strncmp(line, "pa\n", 3))
		res = pa(stack);
	else if (!ft_strncmp(line, "pb\n", 3))
		res = pb(stack);
	else if (!ft_strncmp(line, "rr\n", 3))
		res = rr(stack);
	else if (!ft_strncmp(line, "rra\n", 4))
		res = rra(stack);
	else if (!ft_strncmp(line, "rrb\n", 4))
		res = rrb(stack);
	else
		res = 0;
	return (res);
}

int	loop(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!do_mov(line, stack))
			return (0);
		free(line);
		line = get_next_line(0);
	}
	if (!check_stacks(stack))
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	int		res;
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
	res = loop(&stack);
	if (res == 0)
		return (end_program(&stack, 1));
	else if (res == -1)
		return (end_program(&stack, 3));
	return (end_program(&stack, 2));
}
