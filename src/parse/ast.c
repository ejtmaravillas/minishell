/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 03:27:07 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/31 21:35:36 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_astnode	*create_node(t_nodetype ntype, const char *value)
{
	t_astnode	*node;

	node = (t_astnode *)malloc(sizeof(t_astnode));
	if (!node)
		return (NULL);
	if (node)
	{
		node->ntype = ntype;
		node->value = ft_strdup(value);
		node->errmsg = NULL;
		node->child = NULL;
		node->num_child = 0;
	}
	return (node);
}

void	addnode_child(t_astnode *parent, t_astnode *child)
{
	parent->num_child++;
	parent->child = (t_astnode **)ft_realloc(parent->child, \
		parent->num_child * sizeof(t_astnode *));
	parent->child[parent->num_child - 1] = child;
}

void	free_ast(t_astnode *rootnode)
{
	size_t	index;

	index = 0;
	if (rootnode)
	{
		while (index < rootnode->num_child)
			free_ast(rootnode->child[index]);
		free(rootnode->value);
		free(rootnode->errmsg);
		free(rootnode->child);
		free(rootnode);
	}
}
