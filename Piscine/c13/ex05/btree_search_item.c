/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:16:13 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/24 16:47:00 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	*yo(void *a, void *b)
{
	if (a)
		return (a);
	if (b)
		return (b);
	return (0);
}

void	*btree_search_item(t_btree *root,
	void *data, int (*cmp)(void *, void *))
{
	if (!root)
		return (0);
	if (cmp(data, root->item) == 0)
		return (root->item);
	if (root->left && root->right)
		return (yo(btree_search_item(root->left, data, cmp),
				btree_search_item(root->right, data, cmp)));
	if (root->left)
		return (btree_search_item(root->left, data, cmp));
	if (root->right)
		return (btree_search_item(root->right, data, cmp));
	return (0);
}
