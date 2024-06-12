/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:36:39 by llaakson          #+#    #+#             */
/*   Updated: 2024/06/12 23:54:30 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *remain, char *buffer);
char	*ft_free(char **str);
char	*ft_line(char *remain);
char	*ft_remain(char *remain);
int ft_strlen(char *str);
int ft_strlon(char *str);
char *ft_strjoin(char *s1, char *s2);


#endif
