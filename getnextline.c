
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 42

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*buff;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	buff = (char *) malloc((strlen(s1) + strlen(s2) +1) * sizeof(char));
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

/// @brief unifica el resto y el buffer liberando la memoria del buffer al terminar
/// @param res 
/// @param buffer 
/// @return 
char *ft_free(char *res, char *buffer)
{
    char *temp;

    temp = ft_strjoin(res, buffer);
    free(res);
    return (temp);
}

char *ft_next(char *buffer)
{
    int i;
    int j;
    char *line;

    i = 0;
    j = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++; 
    line = calloc(strlen(buffer) - i + 1, sizeof(char));
    i++;
    while (buffer[i])
        line[j++] = buffer[i++];
    free(buffer);
    return (line);
}

/// @brief Realiza la lectura del buffer y corta de forma que devuelve una nueva dirección de memoria 
/// con una copia del str cortado hasta el salto de linea
/// @param buffer 
/// @return 
char *ft_line(const char *buffer)
{
    char    *line;
    int     i;

    i = 0;
    if(!buffer || !buffer[i])
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = calloc(i + 2, sizeof(char));
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

/// @brief Lee el archivo hasta que detecta que hay un salto de linea o un final de archivo
/// @param fd 
/// @param res 
/// @return 
char *ft_readfile(int fd, char *res)
{
    char *buffer;
    int byte_readed;

    if (!res)
        res = calloc(1, 1);
    buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
    byte_readed = 1;
    while (byte_readed > 0)
    {
        byte_readed = read(fd, buffer, BUFFER_SIZE);
        //Memory failed
        if (byte_readed == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[byte_readed] = 0; //check it?
        res = ft_free(res, buffer);
        if (strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return (res);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (!buffer)
    {
        buffer = (char *) malloc(sizeof(char *) * BUFFER_SIZE + 1);
    }
    buffer = ft_readfile(fd, buffer);
    if (!buffer)
        return (NULL);
    line = ft_line(buffer);
    buffer = ft_next(buffer);
    return (line);    
}

int main()
{
    int fd = open("text.txt",O_RDONLY);
    char *buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    char * read_buf;
    int index = 0;

    printf("%d file descriptor \n", fd);
    while ( (buffer = get_next_line(fd)) != 0)
    {
        printf("%s", buffer);
        index++;
    }
    close(fd);
    return (0);
}