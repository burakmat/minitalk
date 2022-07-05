/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 06:59:40 by bmat              #+#    #+#             */
/*   Updated: 2022/07/05 17:50:42 by bmat             ###   ########.fr       */
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

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}

void	send_pid(int target_pid)
{
	char	*self_pid;

	self_pid = ft_itoa(getpid());
	send_signals(target_pid, self_pid);
	send_null(target_pid);
	free(self_pid);
}

void	verification(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message has been received by the server.\n");
}

int	main(int ac, char **av)
{
	int	target_pid;

	signal(SIGUSR1, verification);
	target_pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		if (target_pid == -1)
		{
			write(1, "You should not give '-1' as a pid.\n", 35);
			return (0);
		}
		send_pid(target_pid);
		send_signals(target_pid, av[2]);
		send_null(target_pid);
	}
}
