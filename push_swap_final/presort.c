/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:44:55 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 11:44:55 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_dlist(t_data *d, t_nlist **list_a)
{
	d->top = *list_a;
	d->bottom = (*list_a)->prev;
	d->t_index = 0;
	d->b_index = len_list(list_a) - 1;
}

void	push_num(t_nlist **list_a, t_nlist **list_b, t_data *d, char c)
{
	int	moves;

	if (c == 't')
	{
		moves = d->t_index;
		while (moves-- > 0)
		{
			if (*list_b && in_range((*list_b)->num, d, 's') == 1
				&& in_range((*list_b)->next->num, d, 's') == 0)
				rotate(list_a, list_b, 'r');
			else
				rotate(list_a, list_b, 'a');
		}
	}
	else if (c == 'b')
	{
		moves = d->len - d->b_index;
		while (moves-- > 0)
			rev_rotate(list_a, list_b, 'a');
	}
	if (*list_b && in_range((*list_b)->num, d, 's') == 1
		&& in_range((*list_b)->next->num, d, 's') == 0)
		rotate(list_a, list_b, 'b');
	push (list_a, list_b, 'b');
	reset_dlist(d, list_a);
}

void	push_to_b(t_nlist **list_a, t_nlist **list_b, t_data *d)
{
	while (d->t_index <= d->b_index)
	{
		if (in_range(d->top->num, d, 'p') == 1)
			push_num(list_a, list_b, d, 't');
		else if (in_range(d->top->num, d, 'p') == 1)
			push_num(list_a, list_b, d, 'b');
		else
		{
			d->top = d->top->next;
			d->bottom = d->bottom->prev;
			d->t_index ++;
			d->b_index --;
		}
	}
	if (*list_b && in_range((*list_b)->num, d, 's') == 1
		&& in_range((*list_b)->next->num, d, 's') == 0)
		rotate(list_a, list_b, 'b');
}

void	presort(t_nlist **list_a, t_nlist **list_b, t_data *d)
{
	int	buckets;

	buckets = d->buckets;
	while (--buckets > 0)
	{
		push_to_b(list_a, list_b, d);
		reset_dlist(d, list_a);
		d->i++;
		d->j += 2;
	}
	while (len_list(list_a) > 3)
	{
		push(list_a, list_b, 'b');
		if (in_range((*list_b)->num, d, 's') == 1)
			rotate(list_a, list_b, 'b');
	}
	sort_three(list_a, list_b);
}
