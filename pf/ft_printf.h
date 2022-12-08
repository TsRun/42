/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:52:31 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/08 01:09:56 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEXA "0123456789abcdef"
# define HEXA_MAJ "0123456789ABCDEF"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef	struct	s_opt
{
	int		opt_right;
	int		opt_zero;
	int		size;
	char	opt;
	int		size_opt;
	int		space;
	int		is_ox;
}	t_opt;

int		ft_printf(char const *s, ...);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t len, size_t size);
void	ft_bzero(void *s, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *s, const void *s2, size_t len);
void	*ft_memchr(const void *s, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t len);
size_t	ft_strlen(const char *s1);
char	*ft_strdup(const char *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *str, const char *to_find, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s, const char *sep);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putchar_fd(char str, int fd);
void	ft_putstr_fd(char const *str, int fd);
void	ft_putendl_fd(char const *str, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putchar(char str, int aff);
int		ft_putstr(char const *str, int aff, int size);
int		ft_putnbr(int n, int aff, int opt);
void	ft_putendl(char const *str);
void	ft_putnchar(int n, char c);
int		ft_putchar2(char n, t_opt c);
int		ft_putstr2(const char *n, t_opt c);
int		ft_putnbr2(int n, t_opt c);
int		ft_putunsigned(unsigned int c, int aff, int opt);
int		ft_putunsigned2(unsigned int c, t_opt opt);
int		ft_puthexa(unsigned long long c, int maj, int aff, int p);
int		ft_puthexa2(unsigned long long c, int maj, t_opt opt);
int		ft_putadr(void *adr, int aff);
int		ft_putadr2(void *adr, t_opt opt);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

#endif
