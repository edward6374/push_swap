/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:57:08 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/30 16:44:12 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa_failed(int **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	if (arr)
		free(arr);
	return (0);
}

void	change_array_pa(t_stack *stack, int **arr)
{
	free(stack->stack_a);
	free(stack->supp_a);
	free(stack->stack_b);
	free(stack->supp_b);
	stack->stack_a = arr[0];
	stack->supp_a = arr[1];
	stack->stack_b = arr[2];
	stack->supp_b = arr[3];
	stack->len_a++;
	stack->len_b--;
	free(arr);
}

void	move_pa(t_stack *stack, int **arr)
{
	int	i;

	i = 0;
	arr[0][0] = stack->stack_b[0];
	arr[1][0] = stack->supp_b[0];
	while (++i <= stack->len_a)
	{
		arr[0][i] = stack->stack_a[i - 1];
		arr[1][i] = stack->supp_a[i - 1];
	}
	i = 0;
	while (i < stack->len_b - 1)
	{
		arr[2][i] = stack->stack_b[i + 1];
		arr[3][i] = stack->supp_b[i + 1];
		i++;
	}
	change_array_pa(stack, arr);
}

int	pa(t_stack *stack)
{
	int	i;
	int	**new_arr;

	i = 0;
	if (stack->len_b < 1)
		return (0);
	new_arr = (int **)malloc(sizeof(int *) * 4);
	if (!new_arr)
		return (pa_failed(new_arr, 0));
	while (i < 4)
	{
		if (i == 0 || i == 1)
			new_arr[i] = (int *)malloc(sizeof(int) * (stack->len_a + 1));
		else
			new_arr[i] = (int *)malloc(sizeof(int) * (stack->len_b - 1));
		if (!new_arr[i])
			return (pa_failed(new_arr, i));
		i++;
	}
	move_pa(stack, new_arr);
	if (ft_printf("pa\n") == -1)
		return (0);
	return (1);
}
