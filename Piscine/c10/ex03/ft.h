/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:44:50 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/21 19:09:53 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_number
{
	int	n;
	int	test;
}	t_number;

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

typedef struct s_string
{
	char	*prog;
	char	*prec;
	char	*string;
	int		size;
	int		djvu;
}	t_string;

t_list		*ft_error2(t_list *list, int n, char *str, char *s);
int			ft_error(char *str, int i, char *name);
void		ft_puterror(char *str);
int			ft_strlen(char *str);
void		ft_putstr(char *str);
int			ft_read_file(char *file, int oct, t_string *str, int *size);
void		ft_putnbr(int nb);
int			ft_atoi(char *str);
t_number	ft_atoi2(char *str);
char		**ft_split(char *str, char *sep);
void		ft_putchar(char c);
void		ft_putnstr(char *str, int n);
int			ft_cmp(char *str, char *name);
t_list		*str_modif(char **av, int ac);
void		ft_free_struct(t_list *yo);
int			ft_c_option(t_list *list, char *str);
void		ft_put_struct(t_list *list);
void		ft_read_input(int oct, t_string *str);
void		ft_print_norm(int c, t_string *str, int e);
void		ft_strncat(char *s1, char *s2, int i, int len);
char		*ft_strncpy(char *s1, char *s2, int n);
int			ft_strncmp(char *s1, char *s2, int n);
char		*which_str(t_string *str, int n);
void		str_16(char *str, int n);

#endif
