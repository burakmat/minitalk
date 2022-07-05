/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:37:38 by bmat              #+#    #+#             */
/*   Updated: 2022/03/01 15:50:11 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	max_value(long n)
{
	if (n > 2147483647)
		return (-1);
	else if (n < -2147483648)
		return (0);
	else
		return (n);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	result;
	long	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
		if (result > 2147483647)
			return (max_value(result * sign));
	}
	return (result * sign);
}
