/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:29:13 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/20 22:57:32 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_dict
{
	char	*num;
	int		nb;
}	t_dict;

void	ft_freetab(char **tab);
char	*ft_read_file(int fd);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_puterror(char *str);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
char	**ft_split(char *str, char *sep);
int		ft_strlen(char *str);
int		ft_error(int n, char *name);
char	**ft_parse(char **str);
void	ft_put_tabstr(char **tab);
void	ft_puttab(int *tab, int size);
int		ft_tabstr_len(char **tab);
char	*ft_strdup(char *str);
char	*ft_strndup(char *str, int n);
void	ft_print_nb(char *nb, char **dic);
int		ft_atoi2(char *str);
void	ft_error2(int n, char **dic, char **numbers, int *a);

#endif
