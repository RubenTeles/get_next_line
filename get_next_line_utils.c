/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:56:44 by rteles            #+#    #+#             */
/*   Updated: 2021/11/25 22:17:54 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *string, int c)
{
	int		i;
	char	*rtstr;

	i = 0;
	rtstr = (char *)string;
	while (rtstr[i])
	{
		if (rtstr[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (rtstr[i] == c)
		return (i);
	return (i);
}

int	ft_countn(char *buffer)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			n++;
		i++;
	}
	return (n);
}
