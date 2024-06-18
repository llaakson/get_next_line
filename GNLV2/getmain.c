/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:27:04 by llaakson          #+#    #+#             */
/*   Updated: 2024/06/17 12:52:47 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{

int fd;
char *print;

fd = open("test.txt", O_RDONLY);

//print = get_next_line(fd);
//printf("%s", print);

int i = 10;
while (i--)
{
	print = get_next_line(fd);
	if (print == NULL)
		break ;
	printf("line: %s", print);
}
return (0);
}

