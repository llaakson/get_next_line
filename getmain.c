/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:27:04 by llaakson          #+#    #+#             */
/*   Updated: 2024/06/06 15:15:52 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"
#include <stdio.h>

int main(void)
{

int fd;
char *print;

fd = open("test.txt", O_RDONLY);

//print = get_next_line(fd);

int i = 4;
while (i--)
{
	print = get_next_line(fd);
	printf("%s", print);
}

}

