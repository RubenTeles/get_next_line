/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:03:44 by rteles            #+#    #+#             */
/*   Updated: 2021/11/25 23:30:07 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>  
/* int open (const char* Path, int flags [, int mode ]);
for close // int close(int fd); 
for write // size_t write (int fd, void* buf, size_t cnt); 
//size_t read (int fd, void* buf, size_t cnt);  */

//int open (const char* Path, int flags [, int mode ]); 

/*FLAGS: 
O_RDONLY: read only, 
O_WRONLY: write only, 
O_RDWR: read and write, 
O_CREAT: create file if it doesn’t exist, 
O_EXCL: prevent creation if it already exists*/

int	main()
{
	int			fd;
	int			bytesread;
	char		buffer[BUFFER_SIZE];
	char		*str;
	static int	i;

	fd = open("exemplo.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error Number % d\n", errno);
		perror("Program");
	}
	printf("fd: %d", fd);
	printf("\n1- str:%s", get_next_line(fd));
	printf("\n2- str:%s", get_next_line(fd));
	printf("\n3- str:%s", get_next_line(fd));
	printf("\n4- str:%s", get_next_line(fd));
	printf("\n5- str:%s", get_next_line(fd));
	printf("\n6- str:%s", get_next_line(fd));
	printf("\n");
	return (0);
}

// print which type of error have in a code
// print program detail "Success or failure" 