/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:18:04 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 16:18:04 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

long long	remove_node(t_nlist **list)
{
	int		i;
	t_nlist	*node;

	if (!*list)
		return (3000000000);
	i = (*list)->num;
	if (*list == (*list)->next)
	{
		free(*list);
		*list = NULL;
		return (i);
	}
	node = *list;
	(*list)->prev->next = (*list)->next;
	(*list)->next->prev = (*list)->prev;
	*list = (*list)->next;
	free(node);
	return (i);
}

void	push_node(t_nlist **list, t_nlist *node, int i)
{
	node->num = i;
	if (!*list)
	{
		node->next = node;
		node->prev = node;
	}
	else if ((*list)->prev == NULL)
	{
		node->next = (*list);
		node->prev = (*list);
		(*list)->prev = node;
		(*list)->next = node;
	}
	else
	{
		node->next = (*list);
		node->prev = (*list)->prev;
		(*list)->prev->next = node;
		(*list)->prev = node;
	}
	*list = node;
}

void	run_push(t_nlist **from, t_nlist **to)
{
	long long	i;
	t_nlist		*node;

	i = remove_node(from);
	if (i == 3000000000)
		return ;
	node = (t_nlist *)ft_calloc(1, sizeof(t_nlist));
	if (!node)
	{
		free_list(from);
		free_list(to);
		exit(1);
	}
	push_node(to, node, (int)i);
}

void	b_push(t_nlist **list_a, t_nlist **list_b, char c)
{
	if (c == 'a')
	{
		run_push(list_b, list_a);
	}
	if (c == 'b')
	{
		run_push(list_a, list_b);
	}
}
