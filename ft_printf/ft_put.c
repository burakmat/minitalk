/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:25:24 by bmat              #+#    #+#             */
/*   Updated: 2022/03/17 13:42:58 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	cnt;

	cnt = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(fd, s++, 1);
		cnt++;
	}
	return (cnt);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_putstr_fd("-2147483648", 1));
		write(fd, "-", 1);
		n *= -1;
		cnt++;
	}
	if (n < 10)
		cnt += ft_putchar_fd(n + '0', fd);
	else
	{
		cnt += ft_putnbr_fd(n / 10, fd);
		cnt += ft_putchar_fd(n % 10 + '0', fd);
	}
	return (cnt);
}

int	ft_convert_base(long double n, int base, int c)
{
	char	*b;
	int		cnt;

	cnt = 1;
	if (n < 0)
	{
		n *= -1;
		cnt += ft_putchar_fd('-', 1);
	}
	if (c)
		b = "0123456789ABCDEF";
	else
		b = "0123456789abcdef";
	if (n >= base)
		cnt += ft_convert_base(n / base, base, c);
	write(1, &b[(unsigned long)n % base], 1);
	return (cnt);
}
