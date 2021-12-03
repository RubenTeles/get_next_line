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

/*char	*upbuffer(char	*buffer)
{
	int		lenbf;
	int		len;
	char	*temp;

	lenbf = ft_strchr(buffer, '\n');
	len = ft_strlen(&buffer[lenbf + 1]);
	temp = malloc(sizeof(char) * len + 1);
	ft_strlcpy(temp, &buffer[len], len + 1);
	return (&temp[0]);
}*/

char	*changebuffer(char	*buffer)
{
	int		lenbf;
	int		len;
	char	*temp;

	lenbf = ft_strchr(buffer, '\n');
	len = ft_strlen(&buffer[lenbf + 1]);
	temp = malloc(sizeof(char) * len + 1);
	ft_strlcpy(temp, &buffer[len], len + 1);
	ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	ft_strlcpy(buffer, temp, len + 1);
	return (buffer);
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
		if (bytesread <= 0)
			return (0);
		lenstr = ft_strlen(str);
		lenbf = ft_strchr(buffer, '\n');
		temp = malloc(sizeof(char) * (lenbf + lenstr + 1));
		ft_strlcpy(temp, str, lenstr + 1);
		ft_strlcpy(&temp[lenstr], buffer, lenbf + 1);
		free(str);
		str = temp;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*str;

	str = new(buffer[fd], fd, 1);
	return (str);
}
