/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:58:06 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/24 15:40:53 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	int		aux;
	va_list	ptr;

	count = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			aux = ft_handle_args(&ptr,*str);
			if (aux >= 0)
				count += aux;
		}
		else
		{
			write(1, str, 1);
			count++;
		}
		str++;
	}
	va_end(ptr);
	return (count);
}
