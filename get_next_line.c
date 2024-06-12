/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:43:43 by llaakson          #+#    #+#             */
/*   Updated: 2024/06/13 00:30:36 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <strings.h>

char *ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_remain(char *remain)
{
	remain = strchr(remain, '\n');
	remain++;
	return (remain);
}

char	*ft_line(char *remain)
{
	char *ret;
	
	ret = strndup(remain, (ft_strlon(remain) + 1));
	return (ret);

}
char	*ft_read(int fd, char *remain, char *buffer)
{
	char *temp_buffer;
	int sz;

	while (1)
	{
		sz = read(fd, buffer, BUFFER_SIZE);
		if (sz >= 0)
		{
			buffer[sz] = '\0';
			temp_buffer = remain;
			remain = ft_strjoin(temp_buffer, buffer);
		}
		if ( sz < 0)
		{
			ft_free(&buffer);
			return (NULL);
		}
		if (strchr(remain, '\n'))
			return (remain);
		if (ft_strlen(remain) == 0)
			return (NULL);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remain;
	char 		*puta;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	remain = ft_read(fd, remain, buffer);
	puta = ft_line(remain);
	remain = ft_remain(remain);
	
	return (puta);
}
