/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:04:33 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/05 14:25:29 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_strchr(char *str, char c);
char	*ft_realloccat(char *s1, char *s2, int len);
char	*ft_lastline(char **s);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 42
#endif

#endif
