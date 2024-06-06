/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:43:43 by llaakson          #+#    #+#             */
/*   Updated: 2024/06/06 15:50:59 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"
#include <stdio.h>
#include <strings.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new_string[j] = s1[i];
		++i;
		++j;
	}
	while (*s2)
	{
		new_string[j] = *s2;
		s2++;
		++j;
	}
	new_string[j] = '\0';
	return (new_string);
}
int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

int ft_strlon(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return(i);
}

char	*get_next_line(int fd)
{
int			sz;
char		*buffer;
static char	*remain; 
char		*ret;

remain = "";
if (fd == 0)
	return (NULL);
buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE+1);
ret = (char *)malloc(sizeof(char) * BUFFER_SIZE+1);

while (1 /*read(fd, buffer, BUFFER_SIZE) > 0*/)
{
	if ((sz = read(fd,buffer, BUFFER_SIZE)) > 0)
	{
	//read(fd, buffer, BUFFER_SIZE);
	remain = ft_strjoin(remain, buffer);
	}
	//printf("%s\n",remain);
	if ( strchr(remain, '\n') != NULL)
	{
		strlcpy(ret, remain, ft_strlon(remain)+2);
		remain = strchr(remain, '\n');
		//printf("AAAAAAAAA    %s\n",remain);
		return (ret);
	}
}
return (ret);

}
