/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:17:07 by llaakson          #+#    #+#             */
/*   Updated: 2024/06/12 23:23:24 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <strings.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_string;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (strdup(s2));
	if (s1 && !s2)
		return (strdup(s1));
	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_string == NULL)
		return (NULL);
	j = 0;
	while (*s1)
	{
		new_string[j] = *s1;
		s1++;
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlon(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}
