/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:24 by gblanca-          #+#    #+#             */
/*   Updated: 2024/05/07 12:47:41 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	send_signal(pid_t pid, unsigned char c);
static void	send_message(pid_t pid, const char *str);

static void	send_message(pid_t pid, const char *str)
{
	while (*str)
	{
		send_signal(pid, *str);
		str++;
	}
}

static void	send_signal(pid_t pid, unsigned char c)
{
	int	n;

	n = sizeof(char) * 8 - 1;
	printf("\n");
	while (n >= 0)
	{
		printf("%d", (c >> n) & 1);
		if ((c >> n--) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(42);
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	pid_t pid;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		send_message(pid, argv[2]);
	}
	else
	{
		printf("Error requires argumments: PID,message \n");
	}
	return (0);
}
