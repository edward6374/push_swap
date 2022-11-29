/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:00:48 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/29 12:59:26 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	my_atoi(char *str, int mode)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	res *= sign;
	if (res > 2147483647 || res < -2147483648)
		return (0);
	if (!mode)
		return (1);
	else
		return ((int)res);
}

int	does_exist(char	*str, char **argv, int i)
{
	int	j;

	j = 0;
	while (argv[j])
	{
		if (j != i)
		{
			if (ft_strncmp(str, argv[j], ft_strlen(argv[j])) == 0)
				return (0);
		}
		j++;
	}
	return (1);
}

int	is_number_and_int(char *str)
{
	int	i;
	int	sign;

	i = -1;
	sign = 0;
	while (str[++i])
	{
		if (str[i] == '-' && i == 0)
		{
			sign = -1;
			i++;
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	if (((sign == 1 || sign == -1) && i == 1) || (i > 11 && sign == 0)
		|| (i > 12 && (sign == 1 || sign == -1)) || !my_atoi(str, 0))
		return (0);
	return (1);
}

int	check_args(char **argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[++i])
	{
		if (ft_strncmp(argv[i], "0", 1) == 0
			|| ft_strncmp(argv[i], "-0", 1) == 0)
			count++;
		if ((ft_strncmp(argv[i], "0", 1) == 0
				|| ft_strncmp(argv[i], "-0", 1) == 0) && count == 2)
			return (0);
		if (!is_number_and_int(argv[i]) || !does_exist(argv[i], argv, i))
			return (0);
	}
	return (1);
}
