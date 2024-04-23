/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:59:09 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/17 13:08:06 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	i;
	size_t	len2;

	i = 0;
	len2 = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= len2)
		len = 0;
	if (len2 - start < len)
		len = len2 - start;
	buffer = (char *) malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	while (i < len)
	{
		buffer[i] = s[start + i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
