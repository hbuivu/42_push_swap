/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:55:56 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 11:55:56 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_nlist **list_a, t_nlist **list_b, t_mlist *m)
{
	int	moves_a;
	int	moves_b;

	moves_a = m->index_a;
	moves_b = m->index_b;
	while (moves_a > 0 && moves_b > 0)
	{
		rotate(list_a, list_b, 'r');
		moves_a--;
		moves_b--;
	}
	while (moves_a > 0)
	{
		rotate(list_a, list_b, 'a');
		moves_a--;
	}
	while (moves_b > 0)
	{
		rotate(list_a, list_b, 'b');
		moves_b--;
	}
}

void	rrr(t_nlist **list_a, t_nlist **list_b, t_mlist *m)
{
	int	moves_a;
	int	moves_b;

	moves_a = len_list(list_a) - m->index_a;
	moves_b = len_list(list_b) - m->index_b;
	while (moves_a > 0 && moves_b > 0)
	{
		rev_rotate(list_a, list_b, 'r');
		moves_a--;
		moves_b--;
	}
	while (moves_a > 0)
	{
		rev_rotate(list_a, list_b, 'a');
		moves_a--;
	}
	while (moves_b > 0)
	{
		rev_rotate(list_a, list_b, 'b');
		moves_b--;
	}
}

void	ra_rrb(t_nlist **list_a, t_nlist **list_b, t_mlist *m)
{
	int	moves_a;
	int	moves_b;

	moves_a = m->index_a;
	moves_b = len_list(list_b) - m->index_b;
	while (moves_a > 0)
	{
		rotate(list_a, list_b, 'a');
		moves_a--;
	}
	while (moves_b > 0)
	{
		rev_rotate(list_a, list_b, 'b');
		moves_b--;
	}
}

void	rra_rb(t_nlist **list_a, t_nlist **list_b, t_mlist *m)
{
	int	moves_a;
	int	moves_b;

	moves_a = len_list(list_a) - m->index_a;
	moves_b = m->index_b;
	while (moves_a > 0)
	{
		rev_rotate(list_a, list_b, 'a');
		moves_a--;
	}
	while (moves_b > 0)
	{
		rotate(list_a, list_b, 'b');
		moves_b--;
	}
}

void	push_move(t_nlist **list_a, t_nlist **list_b, t_mlist *m)
{
	int	mid_a;
	int	mid_b;

	mid_a = ft_round((len_list(list_a) / (float)2) - 1);
	mid_b = ft_round((len_list(list_b) / (float)2) - 1);
	if (m->index_a <= mid_a && m->index_b <= mid_b)
		rr(list_a, list_b, m);
	else if (m->index_a > mid_a && m->index_b > mid_b)
		rrr(list_a, list_b, m);
	else if (m->index_a <= mid_a && m->index_b > mid_b)
		ra_rrb(list_a, list_b, m);
	else if (m->index_a > mid_a && m->index_b <= mid_b)
		rra_rb(list_a, list_b, m);
	push(list_a, list_b, 'a');
}
