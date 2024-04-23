/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:30:25 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/23 13:21:12 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h> //atoi
# include <unistd.h>

int		ft_printf(const char *str, ...);

char	*ft_itoa(int n, int *len);

int		ft_printstr(va_list *ptr);

int		ft_printchr(va_list *ptr);

int		ft_printptr(va_list *ptr);

int		ft_printnbr(va_list *ptr, int showsign);

int		ft_handle_args(va_list *ptr, char type);

int		ft_printnumbertohex(va_list *ptr);
#endif