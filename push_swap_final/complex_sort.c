/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:57:49 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 12:57:49 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adjust_max_min(t_mlist *m)
{
	if (m->n < m->cur_min)
		m->cur_min = m->n;
	else if (m->n > m->cur_max)
		m->cur_max = m->n;
}

void	finalize_list(t_nlist **list_a, t_nlist **list_b, t_data *d)
{
	int	min_index;
	int	list_mid;

	min_index = find_index(d->min, list_a);
	list_mid = ft_round((len_list(list_a) / (float)2) - 1);
	if (min_index <= list_mid)
		while ((*list_a)->num > (*list_a)->prev->num)
			rotate(list_a, list_b, 'a');
	else
		while ((*list_a)->num > (*list_a)->prev->num)
			rev_rotate(list_a, list_b, 'a');
}

void	complex_sort(t_nlist **list_a, t_nlist **list_b, t_data *d)
{
	int		sort_buckets;
	t_mlist	*m;

	sort_buckets = d->buckets * 2;
	m = (t_mlist *)ft_calloc(1, sizeof(t_mlist));
	if (!m)
		free_all_four(list_a, list_b, d, m);
	presort(list_a, list_b, d);
	d->j = sort_buckets - 1;
	m->cur_min = (*list_a)->num;
	m->cur_max = (*list_a)->prev->num;
	while (sort_buckets > 0)
	{
		while (*list_b && (in_range((*list_b)->num, d, 's') == 1
				|| in_range((*list_b)->prev->num, d, 's') == 1))
		{
			best_move(list_a, list_b, d, m);
			adjust_max_min(m);
			push_move(list_a, list_b, m);
		}
		sort_buckets--;
		d->j--;
	}
	finalize_list(list_a, list_b, d);
	free(m);
}
