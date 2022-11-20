/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:08:13 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/20 17:10:00 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pb_failed(int **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	if (arr)
		free(arr);
	ft_printf("Malloc failed!\n");
	return (0);
}

void	change_array_pb(t_stack *stack, int **arr)
{
	free(stack->stack_a);
	free(stack->supp_a);
	free(stack->stack_b);
	free(stack->supp_b);
	stack->stack_b = arr[0];
	stack->supp_b = arr[1];
	stack->stack_a = arr[2];
	stack->supp_a = arr[3];
	stack->len_b++;
	stack->len_a--;
	free(arr);
}

void	move_pb(t_stack *stack, int **arr)
{
	int	i;

	i = 0;
	arr[0][0] = stack->stack_a[0];
	arr[1][0] = stack->supp_a[0];
	while (++i <= stack->len_b)
	{
		arr[0][i] = stack->stack_b[i - 1];
		arr[1][i] = stack->supp_b[i - 1];
	}
	i = 0;
	while (i < stack->len_a - 1)
	{
		arr[2][i] = stack->stack_a[i + 1];
		arr[3][i] = stack->supp_a[i + 1];
		i++;
	}
	change_array_pb(stack, arr);
}

int	pb(t_stack *stack)
{
	int	i;
	int	**new_arr;

	i = 0;
	if (stack->len_a < 1)
	{
		ft_printf("PB Failed\n");
		return (0);
	}
	new_arr = (int **)malloc(sizeof(int *) * 4);
	if (!new_arr)
		return (pb_failed(new_arr, 0));
	while (i < 4)
	{
		if (i == 0 || i == 1)
			new_arr[i] = (int *)malloc(sizeof(int) * (stack->len_b + 1));
		else
			new_arr[i] = (int *)malloc(sizeof(int) * (stack->len_a - 1));
		if (!new_arr[i])
			return (pb_failed(new_arr, i));
		i++;
	}
	move_pb(stack, new_arr);
	ft_printf("pb\n");
	return (1);
}
