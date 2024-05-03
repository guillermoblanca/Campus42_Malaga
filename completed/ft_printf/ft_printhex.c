/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:01:28 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/24 15:25:35 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned long num)
{
	int	c;

	c = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		c++;
		num /= 16;
	}
	return (c);
}

void	ft_printupperhex(unsigned int nbr)
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
		ft_printupperhex(nbr / 16);
		write(1, &c, 1);
	}
}

void	ft_printlowerhex(unsigned int nbr)
{
	unsigned int	remainder;
	char			c;

	if (nbr != 0)
	{
		remainder = nbr % 16;
		if (remainder < 10)
			c = '0' + remainder;
		else
			c = '7' + remainder + 32;
		ft_printlowerhex(nbr / 16);
		write(1, &c, 1);
	}
}

int	ft_printnumbertohex(va_list *ptr, int isupper)
{
	unsigned int	nbr;

	nbr = va_arg(*ptr, unsigned int);
	if (nbr == 0)
		write(1, &"0", 1);
	if (isupper)
		ft_printupperhex(nbr);
	else
		ft_printlowerhex(nbr);
	return (ft_hexlen(nbr));
}
