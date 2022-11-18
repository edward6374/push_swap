/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:25:51 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/18 11:48:39 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	else
	{
		if (!check_args(argv))
			return (end_program(&stack, 1));
		if (!init_stack(&stack, argc, argv))
			return (end_program(&stack, 1));
	}
	print_stack(&stack);
	ft_printf("Everything good!\n");
	end_program(&stack, 0);
	return (0);
}
