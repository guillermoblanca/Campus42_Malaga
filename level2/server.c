/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:47 by gblanca-          #+#    #+#             */
/*   Updated: 2024/05/08 13:21:11 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libraries/libft/libft.h"

static void	receive_message(int signum, siginfo_t *info, void *context)
{
	static int *n;
	static char c;
	static pid_t pid;

	if (pid != info->si_pid && pid != 0)
		return ;
	if (n == NULL)
	{
		n = (int *) malloc(sizeof(int));
		*n = 0;
		c = 0;
		pid = 0;
	}
	pid = info->si_pid;
	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = (c << 1) | 0;
	*n = *n + 1;
	if (*n == 8)
	{
		write(1, &c, 1);
		*n = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	struct sigaction	sa2;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_message;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		printf("Cannot set SIGUSR1 signal...\n");
		return (-1);
	}
	sa.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = receive_message;
	sigemptyset(&sa.sa_mask);
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
