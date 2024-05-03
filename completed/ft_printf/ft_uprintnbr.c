/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uprintnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:52:42 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/24 14:58:13 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unumlen(unsigned int n);

static void	ft_uputnbr_fd(unsigned int n, int fd);

int	ft_printunbr(va_list *ptr)
{
	unsigned int	n;
	int				len;

	n = va_arg(*ptr, unsigned int);
	len = ft_unumlen(n);
	ft_uputnbr_fd(n, 1);
	return (len);
}

static int	ft_unumlen(unsigned int n)
{
	int	c;

	c = 1;
	while (n >= 10)
	{
		c++;
		n /= 10;
	}
	return (c);
}

static void	ft_uputnbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n == 4294967295)
	{
		write(fd, &"4294967295", 10);
		return ;
	}
	if (n >= 10)
	{
		ft_uputnbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}
