/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:21:38 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/24 15:06:42 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

t_btree	*btree_create_node(char *item);
void	btree_apply_prefix(t_btree *root, void (*applyf)(char *));
void	btree_apply_infix(t_btree *root, void (*applyf)(char *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(char *));
void	btree_insert_data(t_btree **root, char *data, int (*cmpf)(char *, char *));
void	*btree_search_item(t_btree *root, char *data, int (*cmp)(char *, char *));
int	btree_level_count(t_btree *root);
void    btree_apply_by_level(t_btree *root, void (*applyf)(char *item,
         int current_level, int is_first_elem));
void	ft_putnbr(int nb);
void	ft_putstr(char *str);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_create(int ac, char **av, t_btree **root)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		btree_insert_data(root, strdup(av[i]), &ft_strcmp);
		i++;
	}
}

void	ft_putstr2(char *str)
{
	write(1, str, strlen(str));
	write(1, "\n", 1);
}

void	ft_putlvl(char *str, int a, int b)
{
	if (b)
		write(1, "first elem: ", 12);
	else
	{
		ft_putnbr(a);
		ft_putstr(" level: ");
	}
	ft_putstr2(str);

}

int	main(int ac, char **av)
{
	t_btree	**root;

	root = malloc(sizeof(t_btree *));
	ft_create(ac - 1, av + 1, root);
	btree_apply_by_level(*root, &ft_putlvl);
	printf("%d\n", btree_level_count(*root));
}
