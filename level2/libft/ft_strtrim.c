/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:20:15 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/15 15:49:31 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contains(char const *set, char const c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*buff;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) - 1;
	if (len == 0)
		return (NULL);
	while (ft_contains(set, s1[i]))
		i++;
	if (i == len + 1)
		return (ft_strdup(""));
	while (ft_contains(set, s1[len]))
		len--;
	buff = (char *)malloc(sizeof(char) * (len - i + 2));
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, (char *) s1 + i, len - i + 2);
	return (buff);
}
