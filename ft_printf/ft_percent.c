/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:50:04 by bmat              #+#    #+#             */
/*   Updated: 2022/03/17 13:43:59 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(char c, va_list ap)
{
	int	cnt;

	cnt = 0;
	if (c == '%')
		cnt += ft_putchar_fd('%', 1);
	else if (c == 'd' || c == 'i')
		cnt += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'c')
		cnt += ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		cnt += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'u')
		cnt += ft_convert_base(va_arg(ap, unsigned int), 10, 1);
	else if (c == 'x')
		cnt += ft_convert_base(va_arg(ap, unsigned int), 16, 0);
	else if (c == 'X')
		cnt += ft_convert_base(va_arg(ap, unsigned int), 16, 1);
	else if (c == 'p')
	{
		write(1, "0x", 2);
		cnt += ft_convert_base(va_arg(ap, unsigned long), 16, 0) + 2;
	}
	return (cnt);
}
