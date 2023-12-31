/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:29:05 by msimic            #+#    #+#             */
/*   Updated: 2023/10/13 11:53:58 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_create_buffer(char *rest_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
		i++;
	if (!rest_str[i])
	{
		free(rest_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rest_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (rest_str[i])
		str[j++] = rest_str[i++];
	str[j] = '\0';
	free(rest_str);
	return (str);
}

static char	*get_line(char *rest_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!rest_str[i])
		return (NULL);
	while (rest_str[i] && rest_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
	{
		str[i] = rest_str[i];
		i++;
	}
	if (rest_str[i] == '\n')
	{
		str[i] = rest_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_create_buffer(int fd, char *rest_str)
{
	char	*buf;
	int		rd_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(rest_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			free(rest_str);
			return (NULL);
		}
		buf[rd_bytes] = '\0';
		rest_str = ft_strjoin(rest_str, buf);
	}
	free(buf);
	return (rest_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest_str = read_create_buffer(fd, rest_str);
	if (!rest_str)
		return (NULL);
	line = get_line(rest_str);
	rest_str = free_create_buffer(rest_str);
	return (line);
}

/* # include <stdio.h>

int	main(void)
{
	int	fd;
	char	*str = NULL;

	fd = open("ba.txt", O_RDWR);
	if (fd == -1)
		return (-1);
	str = get_next_line(fd);
	//str = get_next_line(0);
	//printf("%s", str);
	//return (0);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
} */