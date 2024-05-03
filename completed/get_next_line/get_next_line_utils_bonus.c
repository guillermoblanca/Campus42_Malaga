/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:57:02 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/29 13:58:47 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*buff;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	buff = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) +1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (s1[i])
	{
		buff[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		buff[i + j] = s2[j];
		j++;
	}
	buff[i + j] = '\0';
	return (buff);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = num * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

char	*ft_strchr(const char *s, int c)
{
	c = c % 256;
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (NULL);
}
