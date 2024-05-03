/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:39:35 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/10 14:08:41 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*buffer;
	char	*temp_str;

	temp_str = (char *) str;
	len = ft_strlen(str) + 1;
	buffer = (char *) malloc(sizeof(char) * len);
	if (buffer == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(buffer, temp_str, len);
	return (buffer);
}
