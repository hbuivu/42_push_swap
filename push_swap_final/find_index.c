/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:51:17 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 11:54:52 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(int num, t_nlist **list)
{
	int		i;
	int		len;
	t_nlist	*cur;

	i = 0;
	len = len_list(list);
	cur = *list;
	while (i < len)
	{
		if (cur->num == num)
			return (i);
		i++;
		cur = cur->next;
	}
	return (-1);
}

int	find_lowmid_index(int num, t_nlist **list_a)
{
	int		i;
	t_nlist	*cur;

	i = len_list(list_a);
	cur = (*list_a)->prev;
	while (i >= 0)
	{
		if (num > cur->num)
			return (i);
		cur = cur->prev;
		i--;
	}
	return (i);
}

int	find_minmax_index(int num, t_nlist **list_a, t_mlist *m)
{
	int		i;
	int		len;
	t_nlist	*cur;

	i = 0;
	len = len_list(list_a);
	cur = (*list_a);
	if ((*list_a)->num > (*list_a)->prev->num)
	{
		while (i < len)
		{
			if (cur->num == m->cur_min)
				return (i);
			i++;
			cur = cur->next;
		}
	}
	else
	{
		if (num < m->cur_min)
			return (0);
		else if (num > m->cur_max)
			return (len_list(list_a));
	}
	return (-1);
}

int	find_new_index(int num, t_nlist **list_a, t_mlist *m)
{
	int		i;
	int		len;
	t_nlist	*cur;

	if (num < m->cur_min || num > m->cur_max)
		i = find_minmax_index(num, list_a, m);
	else if (num < (*list_a)->num && num < (*list_a)->prev->num)
		i = find_lowmid_index(num, list_a);
	else
	{
		i = 0;
		len = len_list(list_a);
		cur = *list_a;
		while (i < len)
		{
			if (num < cur->num)
				return (i);
			cur = cur->next;
			i++;
		}
	}
	return (i);
}
