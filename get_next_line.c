/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:53:35 by rteles            #+#    #+#             */
/*   Updated: 2021/11/25 23:43:13 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	ft_putvar(char	**var, char *buffer, int bytesread, int fd)
{
	int				lenb;
	int				lenv;
	char			*temp;

	while (ft_countn(*var) == 0 && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0 && *var[0] == '\0')
			return (0);
		buffer[bytesread] = '\0';
		lenb = ft_strlen(buffer);
		lenv = ft_strlen(*var);
		temp = (char *)malloc(sizeof(char) * (lenb + lenv + 1));
		if (!temp)
			return (0);
		ft_strlcpy(temp, *var, lenv + 1);
		ft_strlcpy(temp + lenv, buffer, lenb + 1);
		free(*var);
		*var = temp;
	}
	return (1);
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

char	*ft_createvar(int bytesread, int fd)
{
	char	*var;

	var = malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
	char			buffer[BUFFER_SIZE + 1];
	char			*str;
	static char		*var;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (var == 0)
	{
		var = ft_createvar(0, fd);
		if (!var)
			return (0);
	}
	if (ft_putvar(&var, buffer, 1, fd) == 0)
		return (0);
	i = ft_strchr(var, '\n');
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, var, i + 1);
	if (i == 0)
		i = 1;
	else if (var[i + 1] != '\0')
		i++;
	if (ft_addvar(&var, i) == 0)
		return (0);
	return (str);
}
