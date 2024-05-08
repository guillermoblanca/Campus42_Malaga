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
#include "libft/libft.h"

static void	receive_message(int signum)
{
	static int n;
	static char c;

	if (signum == -1)
	{
		n = 0;
		c = 0;
	}
	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = (c << 1) | 0;
	n++;
	if (n == 8)
	{
		write(1, &c, 1);
		n = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = receive_message;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	printf("%sServer initialized...%s\n",GREEN, NC);
	printf("PID: %d \n", getpid());
	while (1)
		pause();
	return (0);
}
