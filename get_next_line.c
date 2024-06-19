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

int	get_line_break(char	*buffer)
{
	int	line_break;

	line_break = 0;
	while (buffer[line_break] && buffer[line_break] != '\n')
		line_break++;
	if (buffer[line_break] == '\n')
		line_break++;
	return (line_break);
}

char	*read_file(int fd, char *buffer)
{
	char	*tmp_buf;
	ssize_t	bytes;

	bytes = 1;
	tmp_buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp_buf)
		return (NULL);
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, tmp_buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free(tmp_buf), NULL);
		else
		{
			tmp_buf[bytes] = '\0';
			buffer = ft_strjoin(buffer, tmp_buf);
		}
		if (buffer == 0)
			return (free(tmp_buf), NULL);
	}
	free(tmp_buf);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		line_break;

	line_break = 0;
	if (!buffer[line_break])
		return (NULL);
	line_break = get_line_break(buffer);
	line = (char *)malloc(sizeof(char) * (line_break + 1));
	if (!line)
		return (NULL);
	line_break = 0;
	while (buffer[line_break] && buffer[line_break] != '\n')
	{
		line[line_break] = buffer[line_break];
		line_break++;
	}
	if (buffer[line_break] == '\n')
		line[line_break++] = '\n';
	line[line_break] = '\0';
	return (line);
}

char	*store_buffer(char *buffer)
{
	char	*new_buff;
	int		line_break;
	int		i;
	int		len;

	i = 0;
	if (!buffer[0])
	{
		free(buffer);
		return (NULL);
	}
	line_break = get_line_break(buffer);
	len = ft_strlen(buffer) - line_break + 1;
	new_buff = (char *)malloc(len * sizeof(char));
	if (!new_buff)
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[line_break])
		new_buff[i++] = buffer[line_break++];
	new_buff[i] = '\0';
	free(buffer);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = store_buffer(buffer);
	return (line);
}
