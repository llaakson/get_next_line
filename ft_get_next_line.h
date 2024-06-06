/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:36:39 by llaakson          #+#    #+#             */
/*   Updated: 2024/06/06 12:54:37 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#define BUFF_SIZE 100

char	*get_next_line(int fd);
int ft_strlen(const char *str);
int ft_strlon(const char *str);
char *ft_strjoin(char const *s1, char const *s2);

#endif
