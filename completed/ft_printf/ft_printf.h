/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:30:25 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/24 15:28:24 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h> //atoi
# include <unistd.h>

int		ft_printf(const char *str, ...);

int		ft_printstr(va_list *ptr);

int		ft_printchr(va_list *ptr);

int		ft_printptr(va_list *ptr);

int		ft_printnbr(va_list *ptr);

int		ft_printunbr(va_list *ptr);

int		ft_handle_args(va_list *ptr, char type);

int		ft_printnumbertohex(va_list *ptr, int isupper);

int		ft_hexlen(unsigned long num);
#endif