/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:41:16 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/16 18:31:36 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	populate_minmax(t_nlist **list_a, t_data *d)
{
	int		head;
	int		min;
	int		max;
	t_nlist	*cur;

	head = (*list_a)->num;
	min = (*list_a)->num;
	max = (*list_a)->num;
	cur = (*list_a)->next;
	while (cur->num != head)
	{
		if (cur->num < min)
			min = cur->num;
		if (cur->num > max)
			max = cur->num;
		cur = cur->next;
	}
	d->min = min;
	d->max = max;
}

void	find_pivots(t_data *d)
{
	int	i;
	int	range;

	i = 0;
	range = ft_round((((double)d->max - (double)d->min) / (double)d->buckets));
	while (i < d->buckets)
	{
		d->pivots[i] = d->min + (i * range);
		i++;
	}
	d->pivots[i] = d->max;
	i = 0;
	while (i < d->buckets)
	{
		d->subpivots[i] = d->min + ft_round(((double)range / 2) + (i * range));
		i++;
	}
	i = 0;
	while (i < d->buckets * 2)
	{
		d->allpivots[i] = ft_round((double)d->min + (((double)range / 2) * i));
		i++;
	}
	d->allpivots[i] = d->max;
}

t_data	*init_dlist(t_nlist **list_a, t_nlist **list_b)
{
	t_data	*d;

	d = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!d)
		free_all_three(list_a, list_b, d);
	populate_minmax(list_a, d);
	d->len = len_list(list_a);
	d->buckets = 2 + (d->len / 100);
	d->top = *list_a;
	d->bottom = (*list_a)->prev;
	d->t_index = 0;
	d->b_index = d->len - 1;
	d->i = 0;
	d->j = 0;
	d->pivots = (int *)ft_calloc(d->buckets + 1, sizeof(int));
	d->subpivots = (int *)ft_calloc(d->buckets, sizeof(int));
	d->allpivots = (int *)ft_calloc((2 * d->buckets) + 1, sizeof(int));
	if (!d->pivots || !d->subpivots || !d->allpivots)
		free_all_three(list_a, list_b, d);
	find_pivots(d);
	return (d);
}
