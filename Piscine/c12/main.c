/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:13:54 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/24 01:12:35 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"
#include <unistd.h>
#include <string.h>

void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
t_list *ft_list_last(t_list *begin_list);
t_list	*ft_create_elem(void *data);
t_list	*ft_list_push_strs(int size, char **av);
void ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
t_list  *ft_list_at(t_list *begin_list, unsigned int nbr);
void	ft_list_reverse(t_list **begin_list);
void	ft_list_foreach(t_list *begin, void(*f)(char *));
void	ft_list_foreach_if(t_list *begin, void(*f)(char *), char *dataref, int (*cmp)(char *, char *));
t_list  *ft_list_find(t_list *begin_list, char *dataref, int (*cmp)(char *, char *));
void    ft_list_remove_if(t_list **begin_list, char *dataref, int (*cmp)(char *, char *), void (*free_fct)(void *));
void ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void    ft_list_sort(t_list **begin, int (*cmp)(char *, char *));
void    ft_list_reverse_fun(t_list *begin);
void    ft_sorted_list_insert(t_list **begin, char *data, int (*cmp)(char *, char *));
void    ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)(char *, char *));

char	**ft_strdupdup(char **av, int ac)
{
	int		i;
	char	**tab;

	tab = malloc(ac * sizeof(char *));
	i = 0;
	while (i < ac)
	{
		tab[i] = strdup(av[i]);
		i++;
	}
	return (tab);
}

void	ft_free(void *t)
{
	free(t);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

void	ft_put_struct(t_list *begin)
{
	while (begin)
	{
		ft_putstr(begin->data);
		begin = begin->next;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	main(int ac, char **av)
{
	t_list	**begin;
	t_list	**begin2;
	char	**test;

	begin2 = malloc(sizeof(t_list *));
	test = (ft_strdupdup(av + 1, ac - 1));
	begin = malloc (sizeof(t_list *));
	*begin = ft_list_push_strs(ac - ac, test);
	test[0] = strdup("ab");
	test[1] = strdup("wesh");
	test[2] = strdup("iiii");
	*begin2 = ft_list_push_strs(3, test);
	ft_list_sort(begin, &ft_strcmp);
	ft_list_sort(begin2, &ft_strcmp);
	ft_list_push_back(begin, strdup("yo"));
	ft_sorted_list_merge(begin, *begin2, &ft_strcmp);
	ft_put_struct(*begin);
	ft_list_clear(*begin, &ft_free);
	free(begin2);
	free(test);
	free(begin);
	return (0);
}
