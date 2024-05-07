/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:47 by gblanca-          #+#    #+#             */
/*   Updated: 2024/05/07 14:46:56 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libraries/libft/libft.h"

static void	recieve_message(int signum)
{
	static int *n;
	static char c;

	if (n == NULL)
	{
		n = (int *) malloc(sizeof(int));
		*n = 0;
		c = 0;
	}
	if (signum == SIGUSR1)
	{
		c <<= 1;
		write(1, &"1", 1);
	}
	else
	{
		write(1, &"0", 1);
		c <<= 0;
	}
	*n = *n + 1;
	if (*n == 8)
	{
		write(1, &c, 1);
		write(1, "--> recieved!", 14);
		ft_putnbr_fd(1, ft_itoa(c));
		write(1, "\n", 1);
		*n = 0;
		c = 0;

	}
}

int	main(void)
{
	struct sigaction	sa;
	struct sigaction	sa2;

	sa.sa_handler = recieve_message;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		printf("Cannot set SIGUSR1 signal...\n");
		return (-1);
	}
	sa2.sa_handler = recieve_message;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		printf("Cannot set SIGUSR2 signal... \n");
		return (-1);
	}
	printf("Server initialized... \n");
	printf("PID: %d \n", getpid());
	while (1)
	{
		sleep(10);
	}
	return (0);
}
