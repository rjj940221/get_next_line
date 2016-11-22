//
// Created by Robert JONES on 2016/11/22.
//
#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd = open("test.c", O_RDWR);
	if (fd != -1)
	{
		char *line;
		while(get_next_line(fd, &line) > 0)
		{
			puts(line);
			ft_strdel(&line);
		}
	}
	return 1;
}
