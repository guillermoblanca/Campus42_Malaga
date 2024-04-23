/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:01:28 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/23 13:25:20 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(unsigned int nbr)
{
	unsigned int	remainder;
	char			c;

	if (nbr != 0)
	{
		remainder = nbr % 16;
		if (remainder < 10)
			c = '0' + remainder;
		else
			c = '7' + remainder;
		ft_printhex(nbr / 16);
		write(1, &c, 1);
	}
}

int	ft_printnumbertohex(va_list *ptr)
{
	unsigned int	nbr;

	nbr = va_arg(*ptr, unsigned int);
	ft_printhex(nbr);
	return (1);
}
