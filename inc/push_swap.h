/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:27:18 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/20 13:50:12 by vduchi           ###   ########.fr       */
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

/*  ---		Sa.c	---  */
int		sa(t_stack *stack);

/*  ---		Sb.c	---  */
int		sb(t_stack *stack);

/*  ---		Ss.c	---  */
int		ss(t_stack *stack);

/*  ---		Pa.c	---  */
int		pa(t_stack *stack);

/*  ---		Pb.c	---  */
int		pb(t_stack *stack);

/*  ---		Ra.c	---  */
int		ra(t_stack *stack);

/*  ---		Rb.c	---  */
int		rb(t_stack *stack);

/*  ---		Rr.c	---  */
int		rr(t_stack *stack);

/*  ---		Rra.c	---  */
int		rra(t_stack *stack);

/*  ---		Rrb.c	---  */
int		rrb(t_stack *stack);

/*  ---		RRR.c	---  */
int		rrr(t_stack *stack);

/*  ---		Checker.c	---  */
int		check_args(char **argv);
int		my_atoi(char *str, int mode);

/*  ---		Utils.c	   ---  */
void	print_stack(t_stack *stack);
int		end_program(t_stack *stack, int i);
int		init_stack(t_stack *stack, int count, char **argv);

/*  ---		Until_five_numbers.c   ---  */
int		two_numbers(t_stack *stack);
int		three_numbers(t_stack *stack);
int		four_numbers(t_stack *stack, int n);
int		five_numbers(t_stack *stack);

/*  ---		Until_hundred_numbers.c   ---  */
int		until_hundred(t_stack *stack);

/*  ---		More_than_hundred_numbers.c   ---  */
int		more_than_hundred(t_stack *stack);

#endif
