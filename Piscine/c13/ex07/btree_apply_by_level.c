/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:16:13 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/24 19:01:59 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

int	max2(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	btree_level_count2(t_btree *root)
{
	if (!root)
		return (0);
	if (root->left && root->right)
		return (1 + max2(btree_level_count2(root->right),
				btree_level_count2(root->left)));
	else if (root->left)
		return (1 + btree_level_count2(root->left));
	else if (root->right)
		return (1 + btree_level_count2(root->right));
	return (1);
}

void	btree_apply_by_level2(t_btree *root, void (*applyf)(void *item,
		int current_level, int is_first_elem), int cur, int i)
{
	if (cur == i)
	{
		applyf(root->item, cur, cur == 1);
		return ;
	}
	else if (cur > i)
		return ;
	if (root->left)
		btree_apply_by_level2(root->left, applyf, cur + 1, i);
	if (root->right)
		btree_apply_by_level2(root->right, applyf, cur + 1, i);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
		int current_level, int is_first_elem))
{
	int	k;
	int	i;

	i = 0;
	if (!root)
		return ;
	k = btree_level_count2(root);
	while (i <= k)
	{
		btree_apply_by_level2(root, applyf, 1, i);
		i++;
	}
}
