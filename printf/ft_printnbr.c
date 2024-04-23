/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:23:39 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/23 13:26:41 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(va_list *ptr, int showsign)
{
	int		n;
	int		len;
	char	*num_str;

	n = va_arg(*ptr, int);
	len = 1;
	num_str = ft_itoa(n, &len);
	if (showsign == 0 && (num_str[0] == '-' || num_str[0] == '+'))
		write(1, num_str + 1, len);
	else
		write(1, num_str, len);
	free(num_str);
	return (len);
}

static int	ft_numlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
 * Converts an integer to a string.
 *
 * @param n The integer to convert.
 * @return The string representation of the integer.
 */
char	*ft_itoa(int n, int *lenght)
{
	char	*str;
	int		sign;
	int		len;

	len = ft_numlen(n);
	*lenght = len;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (sign)
		str[0] = '-';
	while (len-- > sign)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
