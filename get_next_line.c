/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:59:06 by layala-s          #+#    #+#             */
/*   Updated: 2024/05/22 16:59:09 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_break(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (i);
}

char	*find_line(int fd, char *buffer)
{
	ssize_t	bytes;
	size_t	size_buf;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (buf == NULL)
		return (NULL);
	bytes = 1;
	size_buf = ft_strlen(buffer) + ft_strlen(buf);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buf[bytes] = '\0';
		tmp = buffer;
		buffer = (char *)malloc((size_buf + 1) * sizeof(char));
		ft_strcpy(buffer, tmp);
		ft_strcat(buffer, buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	else
	{
		line = find_line(fd, buffer);
	}
	return (line);
}
