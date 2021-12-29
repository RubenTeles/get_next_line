/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:03:44 by rteles            #+#    #+#             */
/*   Updated: 2021/12/29 21:57:04 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int			fd;

	fd = open("exemplo.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error Number % d\n", errno);
		perror("Program");
	}
	printf("fd: %d\n", fd);
	printf("[1] str:%s", get_next_line(fd));
	printf("[2] str:%s", get_next_line(fd));
	printf("[3] str:%s", get_next_line(fd));
	printf("[4] str:%s", get_next_line(fd));
	printf("[5] str:%s", get_next_line(fd));
	printf("[6] str:%s", get_next_line(fd));
	return (0);
}

// print which type of error have in a code
// print program detail "Success or failure" 