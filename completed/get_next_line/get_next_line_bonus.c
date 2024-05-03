/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:58:03 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/29 14:04:21 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *res, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(res, buffer);
	free(res);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(const char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_readfile(int fd, char *res)
{
	char	*buffer;
	int		byte_readed;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(res), NULL);
	byte_readed = 1;
	while (byte_readed > 0)
	{
		byte_readed = read(fd, buffer, BUFFER_SIZE);
		if (byte_readed <= -1)
		{
			free(buffer);
			free(res);
			return (NULL);
		}
		buffer[byte_readed] = '\0';
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_SETSIZE];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	if (buffer[fd] == NULL)
		buffer[fd] = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer[fd] = ft_readfile(fd, buffer[fd]);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}
