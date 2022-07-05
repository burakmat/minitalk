/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 07:10:04 by bmat              #+#    #+#             */
/*   Updated: 2022/07/05 18:11:27 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

void	check_letter(unsigned char *letter, int *counter)
{
	static int	pid_received;
	static int	client_pid;

	if (!pid_received && *letter == 0)
	{
		pid_received = 1;
	}
	else if (pid_received && *letter == 0)
	{		
		kill(client_pid, SIGUSR1);
		pid_received = 0;
		client_pid = 0;
	}
	else if (*letter && !pid_received)
	{
		client_pid *= 10;
		client_pid += (*letter) - 48;
		*letter = 0;
	}
	else
	{
		write(1, letter, 1);
		*letter = 0;
	}
	*counter = 0;
}

void	receiver(int sig)
{
	static unsigned char	letter;
	static int				counter;

	if (sig == SIGUSR1)
	{
		if (counter != 7)
			letter = (letter + 1) << 1;
		else
			letter += 1;
	}
	else if (sig == SIGUSR2)
	{
		if (counter != 7)
			letter = letter << 1;
	}
	if (++counter == 8)
		check_letter(&letter, &counter);
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, receiver);
	signal(SIGUSR2, receiver);
	while (1)
		pause();
}
