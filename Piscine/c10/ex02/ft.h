/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:44:50 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/19 19:38:33 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>

typedef struct s_number
{
	unsigned long long	n;
	int					test;
}	t_number;

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

typedef unsigned long long	t_lol;

t_list				*ft_error2(t_list *list, int n, char *str, char *name);
int					ft_error(char *str, int i, char *name);
void				ft_puterror(char *str);
int					ft_strlen(char *str);
void				ft_putstr(char *str);
void				ft_read_file(char *s, t_lol o, t_number *i, char *n);
void				ft_put_header(char *file_name, t_number i);
void				ft_putnbr(int nb);
int					ft_atoi(char *str);
t_number			ft_atoi2(char *str);
char				**ft_split(char *str, char *sep);
void				ft_putchar(char c);
void				ft_putnstr(char *str, int n);
int					ft_cmp(char *str);
t_list				*str_modif(char **av, int ac);
void				ft_free_struct(t_list *yo);
unsigned long long	ft_c_option(t_list *list, char *str);
void				ft_put_struct(t_list *list);
void				ft_read_input(unsigned long long oct);

#endif
