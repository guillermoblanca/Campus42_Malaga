/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:59:35 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/24 15:15:53 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_args(va_list *ptr, char type)
{
	if (type == 's')
		return (ft_printstr(ptr));
	else if (type == 'c')
		return (ft_printchr(ptr));
	else if (type == 'p')
		return (ft_printptr(ptr));
	else if (type == 'd' || type == 'i')
		return (ft_printnbr(ptr));
	else if (type == 'u')
		return (ft_printunbr(ptr));
	else if (type == 'x')
		return (ft_printnumbertohex(ptr, 0));
	else if (type == 'X')
		return (ft_printnumbertohex(ptr, 1));
	else if (type == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (-1);
}
