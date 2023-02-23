/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:30:00 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/16 19:38:22 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_nlist **list)
{
	int		head;
	t_nlist	*n;

	head = (*list)->num;
	n = (*list)->next;
	while (n->num != head)
	{
		if (n->num < n->prev->num)
			return (0);
		n = n->next;
	}	
	return (1);
}

int	len_list(t_nlist **list)
{
	int		head;
	int		count;
	t_nlist	*cur;

	if (!list || !*list)
		return (0);
	head = (*list)->num;
	cur = (*list)->next;
	count = 1;
	while (cur->num != head)
	{
		count ++;
		cur = cur->next;
	}
	return (count);
}

int	in_range(int n, t_data *d, char c)
{
	if (c == 's')
		if (n >= d->allpivots[d->j] && n <= d->allpivots[d->j + 1])
			return (1);
	if (c == 'p')
		if (n >= d->pivots[d->i] && n < d->pivots[d->i + 1])
			return (1);
	return (0);
}

int	ft_round(double i)
{
	if (i > 2147483647)
		return ((int)i);
	if (i - (int)i > 0 && i - (int)i < 1)
		return ((int)i + 1);
	return ((int)i);
}
