/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:27:18 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/18 11:55:11 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include <stdio.h>

typedef struct s_stack
{
	int	len_a;
	int	len_b;
	int	*stack_a;
	int	*supp_a;
	int	*stack_b;
	int	*supp_b;
}	t_stack;

int		sa(t_stack *stack);
int		sb(t_stack *stack);
int		ss(t_stack *stack);

int		check_args(char **argv);
int		my_atoi(char *str, int mode);
int		end_program(t_stack *stack, int i);
int		init_stack(t_stack *stack, int count, char **argv);

void	print_stack(t_stack *stack);
void	fill_a(t_stack *stack, char **argv);

#endif
