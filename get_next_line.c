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

char	*read_file(int fd, char *buffer)
{
	char	*tmp_buff;
	ssize_t	bytes;

	bytes = 1;
	tmp_buff = (char *)malloc(BUFFER_SIZE + 1 * (sizeof(char)));
	if (!tmp_buff)
		return (NULL);
	while (bytes > 0 && ft_strchr(buffer, '\n') == 0)
	{
		bytes = read(fd, tmp_buff, BUFFER_SIZE);
		if (bytes == -1)
			return (free(tmp_buff), NULL);
		tmp_buff[bytes] = '\0';
		buffer = ft_strjoin(buffer, tmp_buff);
		if (buffer == 0)
			return (free(buffer), NULL);
	}
	free (tmp_buff);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		line_break;

	line_break = 0;
	if (buffer[line_break])
		return (NULL);
	while (buffer[line_break] && buffer[line_break] != '\n')
		line_break++;
	if (buffer[line_break] == '\n')
		line_break++;
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

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if ((fd < 0 || BUFFER_SIZE >= 0) || read(fd, 0, 0) > 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = get_storage(buffer);
	return (line);
}
int	main()
{
	return 0;
}