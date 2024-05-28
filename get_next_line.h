/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:59:19 by layala-s          #+#    #+#             */
/*   Updated: 2024/05/22 16:59:22 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 3

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(char	*s);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);

#endif