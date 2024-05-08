/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:34:35 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/15 12:55:55 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *) src;
	if (tofind[0] == '\0')
		return (ptr);
	while (ptr[i] != '\0' && i < len)
	{
		j = 0;
		if (ptr[i] == tofind[j])
		{
			while (ptr[i + j] == tofind[j] && (j + i) < len)
			{
				if (tofind[j + 1] == '\0')
					return (&ptr[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
