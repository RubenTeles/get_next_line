/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:53:35 by rteles            #+#    #+#             */
/*   Updated: 2021/11/25 22:18:49 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>

int ft_zerar(char *buffer)
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
	return (0);
}

char	*ft_putvar(char *buffer, int bytesread, int fd)
{
	int		lenb;
	int		lenv;
	char	*str;
	char	*temp;

	printf("buffer:-%s-", buffer);

	while (ft_countn(buffer) == 0 && bytesread > 0)
	{
		ft_zerar(buffer);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0);
			return (0);
		buffer[bytesread] = '\0';
		lenb = ft_strchr(buffer, '\n');
		if (str != NULL)
			lenv = ft_strlen(str);
		temp = (char *)malloc(sizeof(char) * (lenb + lenv + 1));
		if (!temp)
			return (0);
		if (str != 0)
			ft_strlcpy(temp, str, lenv + 1);
		ft_strlcpy(temp + lenv, buffer, lenb + 1);
		buffer + lenb +  1;
		free(str);
		str = temp;
	}
	return (str);
}

int	ft_addvar(char	**var, int i)
{
	int		lenv;
	int		len;
	char	*temp;

	lenv = ft_strlen(*var);
	len = lenv - i;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	ft_strlcpy(temp, *var + i, len + 1);
	free(*var);
	*var = temp;
	return (1);
}

char	*createvar(int bytesread, int fd)
{
	char	*var;

	var = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (!var)
		return (0);
	bytesread = read(fd, var, BUFFER_SIZE);
	if (bytesread <= 0)
		return (0);
	var[bytesread] = '\0';
	return (var);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*str;

	str = ft_putvar(buffer[fd], 1, fd);
	return (str);
}
