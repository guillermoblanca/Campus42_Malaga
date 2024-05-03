/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:23:39 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/24 14:55:47 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_fd(int n, int fd);

static int	ft_numlen(int n);

int	ft_printnbr(va_list *ptr)
{
	int	n;
	int	len;

	n = va_arg(*ptr, int);
	len = ft_numlen(n);
	ft_putnbr_fd(n, 1);
	return (len);
}

int	ft_numlen(int n)
{
	int	len;

	len = 1;
	if (n == -2147483648)
	{
		return (11);
	}
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, &"-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, &"-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}
