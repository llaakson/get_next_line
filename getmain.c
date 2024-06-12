/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:27:04 by llaakson          #+#    #+#             */
/*   Updated: 2024/06/12 23:13:50 by llaakson         ###   ########.fr       */
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

//int i = 4;
while (1)
{
	print = get_next_line(fd);
	if (print == NULL)
		break ;
	printf("%s", print);
}
return (0);
}

