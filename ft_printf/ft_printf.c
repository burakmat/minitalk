/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:40:17 by bmat              #+#    #+#             */
/*   Updated: 2022/03/17 17:49:20 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cnt;

	cnt = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
			cnt += ft_percent(*(++str), ap);
		else
			cnt += ft_putchar_fd(*str, 1);
		if (*str)
			str++;
	}
	va_end(ap);
	return (cnt);
}
/*
int main()
{
	char *a = NULL;

	ft_printf("%s every", a);
}
*/
