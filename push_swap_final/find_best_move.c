/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:28:14 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 13:31:57 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_moves(int index_a, int index_b, t_nlist **list_a, t_nlist **list_b)
{
	t_calc	c;

	c.len_a = len_list(list_a);
	c.len_b = len_list(list_b);
	c.mid_a = (c.len_a / 2) - 1;
	c.mid_b = (c.len_b / 2) - 1;
	if (index_a > c.mid_a && index_b > c.mid_b)
	{
		if (c.len_a - index_a >= c.len_b - index_b)
			c.moves = c.len_a - index_a;
		else
			c.moves = c.len_b - index_b;
	}
	else if (index_a <= c.mid_a && index_b <= c.mid_b)
	{
		if (index_a >= index_b)
			c.moves = index_a;
		else
			c.moves = index_b;
	}
	else if (index_a > c.mid_a && index_b <= c.mid_b)
		c.moves = (c.len_a - index_a) + index_b;
	else if (index_a <= c.mid_a && index_b > c.mid_b)
		c.moves = index_a + (c.len_b - index_b);
	return (c.moves);
}

void	check_top(t_nlist **list_a, t_nlist **list_b, t_data *d, t_mlist *m)
{
	int		index_a;
	int		index_b;
	int		moves;
	int		len_b;
	t_nlist	*cur;

	cur = *list_b;
	len_b = len_list(list_b);
	index_a = find_new_index(cur->num, list_a, m);
	index_b = 0;
	while (in_range(cur->num, d, 's') == 1 && index_b < 4 && index_b < len_b)
	{	
		moves = calc_moves(index_a, index_b, list_a, list_b);
		if (moves < m->min_move)
		{
			m->n = cur->num;
			m->min_move = moves;
			m->index_a = index_a;
			m->index_b = index_b;
		}
		cur = cur->next;
		index_a = find_new_index(cur->num, list_a, m);
		index_b ++;
	}
}

void	check_bottom(t_nlist **list_a, t_nlist **list_b, t_data *d, t_mlist *m)
{
	int		index_a;
	int		index_b;
	int		moves;
	int		stop_b;
	t_nlist	*cur;

	cur = (*list_b)->prev;
	index_a = find_new_index(cur->num, list_a, m);
	index_b = len_list(list_b) - 1;
	stop_b = index_b - 4;
	while (in_range(cur->num, d, 's') == 1 && index_b >= 0 && index_b > stop_b)
	{
		moves = calc_moves(index_a, index_b, list_a, list_b);
		if (moves < m->min_move)
		{
			m->n = cur->num;
			m->min_move = moves;
			m->index_a = find_new_index(cur->num, list_a, m);
			m->index_b = index_b;
		}
		cur = cur->prev;
		index_a = find_new_index(cur->num, list_a, m);
		index_b --;
	}
}

void	best_move(t_nlist **list_a, t_nlist **list_b, t_data *d, t_mlist *m)
{
	int		index_a;
	int		index_b;

	index_a = find_new_index((*list_b)->num, list_a, m);
	index_b = 0;
	m->n = (*list_b)->num;
	m->min_move = calc_moves(index_a, index_b, list_a, list_b);
	m->index_a = index_a;
	m->index_b = index_b;
	check_top(list_a, list_b, d, m);
	check_bottom(list_a, list_b, d, m);
}
