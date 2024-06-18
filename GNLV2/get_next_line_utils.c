/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:24:32 by llaakson          #+#    #+#             */
/*   Updated: 2024/06/16 18:40:23 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = malloc((len1 + len2 + 1) * sizeof(char));
	if (!s3)
	{
		free (s1);
		return (NULL);
	}
	ft_memcpy(s3, s1, len1);
	ft_memcpy(s3 + len1, s2, len2);
	s3[len1 + len2] = '\0';
	free(s1);
	return (s3);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		--i;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		++i;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*char_dst;
	char	*char_src;

	char_dst = (char *) dst;
	char_src = (char *) src;
	if (src == NULL && dst == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		char_dst[i] = char_src[i];
		i++;
	}
	return (dst);
}
