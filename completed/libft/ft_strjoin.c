/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:45:53 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/15 11:38:22 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
