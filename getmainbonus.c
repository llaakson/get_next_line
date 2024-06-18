/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:27:04 by llaakson          #+#    #+#             */
/*   Updated: 2024/06/17 17:39:13 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{

int fd;
int fd1;
int fd2;
char *print;

fd = open("test.txt", O_RDONLY);
fd1 = open("test1.txt", O_RDONLY);
fd2 = open("test2.txt", O_RDONLY);

int i = 20;
while (i--)
{
	print = get_next_line(fd);
	if (print)
		printf("%s", print);
	free(print);
	print = get_next_line(fd1);
	if (print)
		printf("%s", print);
	free(print);
	print = get_next_line(fd2);
	if (print)
		printf("%s",print);
	free(print);
}
close (fd);
close (fd1);
close (fd2);
return (0);
}

