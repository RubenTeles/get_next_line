/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:53:35 by rteles            #+#    #+#             */
/*   Updated: 2021/12/29 22:45:17 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_size(char *buffer, int fd)
{
	if (buffer[0] == 0)
		return (read(fd, buffer, BUFFER_SIZE));
	return (ft_strlen(buffer));
}

char	*ft_buffer(char	*buffer, char *temp, int lstr, int size)
{
	int	a;
	int	z;
	int	in;
	int	len;

	in = ft_countn(buffer);
	a = 0;
	z = 0;
	len = lstr + in;
	while (a < size)
	{
		if (a < in)
			temp[a + lstr] = buffer[a];
		else
			buffer[z++] = buffer[a];
		buffer[a++] = 0;
	}
	temp[len] = '\0';
	return (temp);
}

char	*ft_temp(char *buffer, char *str, int size, int len)
{
	int		lstr;
	char	*temp;

	lstr = 0;
	temp = malloc(sizeof(char) * len + 1);
	if (!temp)
		return (str);
	if (str != NULL)
	{
		lstr = len - ft_countn(buffer);
		ft_strlcpy(temp, str, lstr + 1);
	}
	temp = ft_buffer(buffer, temp, lstr, size);
	if (str != NULL)
		free(str);
	str = temp;
	return (str);
}

char	*ft_str(char *buffer, char *str, int fd, int size)
{
	int		in;
	int		len;

	in = 0;
	len = 0;
	while (in == size && isline(str) == 0)
	{
		size = ft_size(buffer, fd);
		if (size <= 0)
			return (str);
		in = ft_countn(buffer);
		len += in;
		str = ft_temp(buffer, str, size, len);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	str = ft_str(buffer[fd], str, fd, 0);
	return (str);
}

/*char	*ft_str(char *buffer, char *str, int fd, int size){
	int		in;
	int		len;
	int		a;
	int		z;
	int		lstr;
	char	*temp;

	in = 0;
	len = 0;
	lstr = 0;
	temp = NULL;
	while (in == size && isline(str) == 0)
	{
		size = ft_size(buffer, fd);
		if (size <= 0)
			return (str);
		in = ft_countn(buffer);
		len += in;
		temp = malloc(sizeof(char) * len + 1);
		if (!temp)
			return (str);
		if (str != NULL)
		{
			lstr = len - in;
			ft_strlcpy(temp, str, lstr + 1);
		}
		z = 0;
		a = 0;
		while (a < size)
		{
			if (a < in)
				temp[a + lstr] = buffer[a];
			else
				buffer[z++] = buffer[a];
			buffer[a++] = 0;
		}
		temp[len] = '\0';
		if (str != NULL)
			free(str);
		str = temp;
	}
	return (str);
}*/