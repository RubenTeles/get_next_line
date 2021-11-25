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

#include "get_next_line.h"
/*
#include <stdio.h>

char	*ft_strmalloc(char *str, char *buffer, int i)
{
	char	*dest;
	int		len;

	len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (0);
	ft_strlcpy(dest, str, len + 1);
	ft_strlcpy(&dest[len], buffer, i + 1);
	printf("\ndest: %s", dest);
	free(str);
	return (dest);
}

char	*ft_strmalloc2(char *str, char *buffer)
{
	char	*dest;
	int		len;
	int		i;

	printf("\nhelperbuffer: -%s-", buffer);
	i = ft_strchr(buffer, '\n');
	len = ft_strlen(buffer) - i;
	printf("\nhelperlen: %d", len);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (0);
	printf("\nhelperbuffer: -%s-", &buffer[i]);
	ft_strlcpy2(dest, &buffer[i], len + 1);
	printf("\nhelpdest: -%s-", dest);
	if (str != NULL)
		free(str);
	return (dest);
}

char	*ft_strmalloc3(char *str, char *buffer, int i)
{
	char	*dest;
	int		len;

	len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (0);
	ft_strlcpy2(dest, str, len + 1);
	ft_strlcpy2(&dest[len], buffer, i + 1);
	free(str);
	return (dest);
}

int	ft_creatstr(int fd, char *buffer, char **str)
{
	int		i;
	int		a;
	int		temp;

	temp = BUFFER_SIZE;
	a = 0;
	i = 0;
	while (a != 1 && i <= temp)
	{
		i += ft_isnewline(buffer, BUFFER_SIZE);
		if (i < temp || buffer[temp - i] == '\n')
		{
			a = 1;
			*str = ft_strmalloc(*str, buffer, i);
		}
		if (a == 0 && i == temp)
		{
			*str = ft_strmalloc(*str, buffer, i);
			a = read(fd, buffer, BUFFER_SIZE);
			if (a <= 0)
				return (i);
			temp += BUFFER_SIZE;
			a = 0;
		}
	}
	return (i);
}

int	ft_strhelp(char **help, char **str)
{
	char	*dest;
	char	*desthelp;
	int		len;
	int		lenhelp;

	lenhelp = ft_strlen(*help);
	len = ft_strchr(*help, '\n');
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (0);
	ft_strlcpy(dest, *help, len + 1);
	free(*str);
	*str = dest;
	desthelp = (char *)malloc(sizeof(char) * (lenhelp - len) + 1);
	if (!desthelp)
		return (0);
	ft_strlcpy(desthelp, *help + len, (lenhelp - len) + 1);
	free(*help);
	*help = desthelp;
	printf("=========");
	return (1);
}

char	*get_next_line1(int fd)
{
	char			buffer[BUFFER_SIZE];
	int				bytesread;
	char			*str;
	static char		*help;

	printf("\n\n--helper aa :-%s-", help);
	str = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!str)
		return (0);
	if (help != 0)
	{
		if (ft_countn(help) > 0)
		{
			ft_strhelp(&help, &str);
			printf("\nhelper cc :-%s-", help);
			return (str);
		}
	}
	bytesread = read(fd, &buffer, BUFFER_SIZE);
	if (bytesread < 0)
		return (0);
	if (help != 0)
	{
		help = ft_strmalloc3(help, buffer, ft_strlen(help) + ft_strlen(buffer));
		printf("\n\n--helper bb :-%s-", help);
		ft_creatstr(fd, help, &str);
	}
	else
		ft_creatstr(fd, buffer, &str);
	if (ft_countn(buffer) > 0)
		help = ft_strmalloc2(help, buffer);
	printf("\nhelper cc :-%s-", help);
	return (str);
}
*/