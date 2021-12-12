/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:43:30 by rteles            #+#    #+#             */
/*   Updated: 2021/12/03 21:58:34 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_zerobuffer(char	*buffer)
{
	long long int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
	return (0);
}

char	*upbuffer(char	*buffer)
{
	int		lenbf;
	int		len;

	lenbf = ft_strchr(buffer, '\n');
	len = ft_strlen(&buffer[lenbf]);
	ft_strlcpy(buffer, &buffer[lenbf], len + 1);
	ft_zerobuffer(&buffer[len + 1]);
	return (buffer);
}

char	*old(char	*buffer)
{
	char	*str;
	int		len;

	str = ft_calloc(sizeof(char), 1);
	if (!str)
		return (0);
	len = ft_strchr(buffer, '\n');
	str = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(str, buffer, len + 1);
	upbuffer(buffer);
	return (str);
}

char	*new(char *buffer, int fd, int bytesread)
{
	int		i;
	char	*str;
	char	*temp;
	int		lenbf;
	int		lenstr;

	str = ft_calloc(sizeof(char), 1);
	if (!str)
		return (0);
	while (ft_countn(buffer) == 0 && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0 || bytesread == 0 && str[0] == '\0')
			return (0);
		else if (bytesread == 0)
			break ;
		lenstr = ft_strlen(str);
		lenbf = ft_strchr(buffer, '\n');
		temp = malloc(sizeof(char) * (lenbf + lenstr + 1));
		ft_strlcpy(temp, str, lenstr + 1);
		ft_strlcpy(&temp[lenstr], buffer, lenbf + 1);
		free(str);
		str = temp;
	}
	upbuffer(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*str;

	if (buffer[fd][0] != '\0')
		str = old(buffer[fd]);
	else if (ft_countn(buffer[fd]) == 0)
		str = new(buffer[fd], fd, 1);
	return (str);
}
