/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:42:49 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/23 14:50:03 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//TODO: Falla la cantidad de caracteres que se ha impreso, 
//el valor no coincide con el real
//fallo al calcular el tamaño de hex que ha impreso,
// quizas sea mejor devolver un str en vez de esta forma
int	ft_printstr(va_list *ptr)
{
	int		c;
	char	*str;

	c = 0;
	str = va_arg(*ptr, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		c++;
	}
	return (c);
}

int	ft_printchr(va_list *ptr)
{
	int		txt;
	char	temp;

	txt = va_arg(*ptr, int);
	temp = (char)txt;
	write(1, &temp, 1);
	return (1);
}

/// @brief TODO: Implement
/// @param ptr 
/// @return 
int	ft_printptr(va_list *ptr)
{
	uint32_t	ptr_ptr;

	ptr_ptr = va_arg(*ptr, uint32_t);
	write(1, "{Requires implementation}", 25);
	return (-1);
}
