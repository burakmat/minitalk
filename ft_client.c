/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:22:20 by bmat              #+#    #+#             */
/*   Updated: 2022/07/05 19:10:29 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	send_signals(int pid, char *str)
{
	int	letter;
	int	bit;

	letter = 0;
	while (str[letter])
	{
		bit = 8;
		while (--bit >= 0)
		{
			if (str[letter] >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		++letter;
	}
}

int	main(int ac, char **av)
{
	int	target_pid;

	target_pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		if (target_pid == -1)
		{
			write(1, "You should not give '-1' as a pid.\n", 35);
			return (0);
		}
		send_signals(target_pid, av[2]);
	}
}
