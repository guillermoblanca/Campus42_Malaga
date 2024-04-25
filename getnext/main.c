/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:48:12 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/24 15:50:43 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int fd = open("text.txt", O_RDONLY, 0);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
	}
	return (0);
}