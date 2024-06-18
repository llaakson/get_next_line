/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:43:43 by llaakson          #+#    #+#             */
/*   Updated: 2024/06/17 13:01:39 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_remain(char *remain, char *buffer, int buf_size)
{
	int	j;

	j = 0;
	while (buffer[j] && buffer[j] != '\n')
		j++;
	if (buffer[j] == '\n')
		j++;
	ft_bzero(remain, BUFFER_SIZE + 1);
	ft_memcpy(remain, (buffer + j), (buf_size - j));
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, buffer, i);
	str[i] = '\0';
	return (str);
}

char	*ft_read(int fd, char *buffer, int *buf_size, char *remain)
{
	int		sz;
	char	temp_buffer[BUFFER_SIZE + 1];

	while (1)
	{
		sz = read(fd, temp_buffer, BUFFER_SIZE);
		if (sz == -1)
		{
			free(buffer);
			remain[0] = 0;
			return (NULL);
		}
		temp_buffer[sz] = '\0';
		if (sz == 0)
			break ;
		buffer = ft_strjoin(buffer, temp_buffer);
		*buf_size += sz;
		if (!buffer || ft_strchr(temp_buffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		remain[BUFFER_SIZE + 1];
	char			*ret;
	int				buf_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buf_size = ft_strlen(remain);
	ft_memcpy(buffer, remain, buf_size);
	buffer[buf_size] = 0;
	if (!(ft_strchr(buffer, '\n')))
		buffer = ft_read(fd, buffer, &buf_size, remain);
	if (!buffer)
		return (NULL);
	ret = ft_get_line(buffer);
	ft_remain(remain, buffer, buf_size);
	free(buffer);
	return (ret);
}
