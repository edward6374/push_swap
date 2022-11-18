/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:57:08 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/18 12:17:10 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	pa_failed(int **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	if (arr)
		free(arr);
	ft_printf("Malloc failed!\n");
	return (0);
}

int	move_pa(t_stack *stack, int **arr)
{
	
}

int	pa(t_stack *stack)
{
	int	i;
	int	**new_arr;

	i = 0;
	if (stack->len_b < 1)
	{
		ft_printf("PA Failed\n");
		return (0);
	}
	new_arr = (int **)malloc(sizeof(int *) * 4);
	if (!new_arr)
		return (pa_failed(new_arr, 0));
	while (i < 4)
	{
		if ((i % 2) == 0)
			new_arr[i] = (int *)malloc(sizeof(int) * (stack->len_a + 1));
		else
			new_arr[i] = (int *)malloc(sizeof(int) * (stack->len_b - 1));
		if (!new_arr[i])
			return (pa_failed(new_arr, i));
	}
	move_pa(stack, new_arr);
	return (1);
}
