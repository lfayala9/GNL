/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:59:33 by layala-s          #+#    #+#             */
/*   Updated: 2024/05/22 16:59:35 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	ch = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (!src || !dest)
		return (0);
	while (size > 1 && src[i])
	{	
		dest[i] = src[i];
		i++;
		size--;
	}
	if (size > 0)
		dest[i] = '\0';
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size < dest_len)
		src_len = src_len + size;
	else
		src_len = src_len + dest_len;
	while (src[i] && (dest_len + i) < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(len + 1 * (sizeof(char)));
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, s1, len + 1);
	ft_strlcat(join, s2, len + 1);
	free(s1);
	return (join);
}
