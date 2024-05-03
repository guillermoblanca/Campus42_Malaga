/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:46:39 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/29 13:09:54 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdio.h> 
# include <stdlib.h> 
# include <fcntl.h> 

char	*ft_free(char *res, char *buffer);

char	*ft_next(char *buffer);

char	*ft_line(const char *buffer);

char	*ft_readfile(int fd, char *res);

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *s);

void	*ft_calloc(size_t num, size_t size);

void	*ft_memset(void *b, int c, size_t len);

char	*ft_strchr(const char *s, int c);

#endif