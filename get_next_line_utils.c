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

size_t	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	char	tmp;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (*src != '\0')
	{
		tmp = *src++;
		dest[i++] = tmp;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	ch;
	int				i;

	ch = (char)c;
	i = 0;
	while (str[i])
	{
		if (ch == c)
			return ((char *)&str[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	dup = (char *)malloc(sizeof(char) + (size + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
