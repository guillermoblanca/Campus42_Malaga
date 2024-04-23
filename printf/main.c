/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:10:53 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/23 14:48:51 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void TEST0()
{
	int c;


	c = printf("%s", (char *) NULL);
	printf("\n%d\n", c);
	c = ft_printf("%s", (char *) NULL);
	printf("\n%d\n", c);
}

int	main(void)
{
	int	c;
	TEST0();
	c = ft_printf("Hello world %d %s %c %x valor 10%%\n", 253, "parseado", 'c', -16);
	c = ft_printf("%d \n", c);
	c = ft_printf("%d", c);
	return (0);
}
