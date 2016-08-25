/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 12:06:15 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/23 17:49:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#define MAX(a,b) ((a > b) ? a : b)

int	g_level = 0;

int		btree_level_count2(t_btree *root)
{
	int	lsize;
	int	rsize;

	if (!root)
		return (0);
	lsize = btree_level_count2(root->left);
	rsize = btree_level_count2(root->right);
	return (1 + MAX(lsize, rsize));
}

void	btree_apply_to_level(
		t_btree *root,
		int level,
		int is_first_elem,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (level == g_level)
	{
		(*applyf)(root->item, level, is_first_elem);
		return ;
	}
	if (root->left)
		btree_apply_to_level(root->left, level + 1, is_first_elem, applyf);
	if (root->right)
		btree_apply_to_level(root->right, level + 1, 0, applyf);
}

void	btree_apply_by_level(
		t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		height;

	height = btree_level_count2(root);
	while (g_level < height)
	{
		btree_apply_to_level(root, 0, 1, applyf);
		g_level++;
	}
}
