/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:16:13 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/24 16:54:09 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item);

void	btree_insert_data(t_btree **root,
	void *data, int (*cmpf)(void *, void *))
{
	int		k;

	if (!*root)
	{
		*root = btree_create_node(data);
		return ;
	}
	k = cmpf(data, (*root)->item);
	if (k >= 0 && !(*root)->right)
		(*root)->right = btree_create_node(data);
	else if (k >= 0)
		btree_insert_data(&(*root)->right, data, cmpf);
	else if (k < 0 && !(*root)->left)
		(*root)->left = btree_create_node(data);
	else if (k < 0)
		btree_insert_data(&(*root)->left, data, cmpf);
}
