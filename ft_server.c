/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:32:12 by bmat              #+#    #+#             */
/*   Updated: 2022/07/05 18:34:41 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

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
	{
		write(1, &letter, 1);
		letter = 0;
		counter = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, receiver);
	signal(SIGUSR2, receiver);
	while (1)
		pause();
}
