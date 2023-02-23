/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:40:29 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 11:40:29 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_nlist **list)
{
	int		head;
	int		min;
	int		position;
	int		count;
	t_nlist	*cur;

	head = (*list)->num;
	min = (*list)->num;
	cur = (*list)->next;
	count = 0;
	position = count;
	while (cur->num != head)
	{
		if (cur->num < min)
		{
			min = cur->num;
			count++;
			position = count;
		}
		else
			count++;
		cur = cur->next;
	}
	return (position);
}

void	sort_three(t_nlist **list_a, t_nlist **list_b)
{
	int	a;
	int	b;
	int	c;

	a = (*list_a)->num;
	b = (*list_a)->next->num;
	c = (*list_a)->next->next->num;
	if (a < b && b < c)
		return ;
	if (a > b && a < c)
		swap(list_a, list_b, 'a');
	else if (a < b && a > c)
		rev_rotate(list_a, list_b, 'a');
	else if (a < b && a < c)
	{
		rev_rotate(list_a, list_b, 'a');
		swap(list_a, list_b, 'a');
	}
	else if (a > b && b < c)
		rotate(list_a, list_b, 'a');
	else if (a > b && b > c)
	{
		swap(list_a, list_b, 'a');
		rev_rotate(list_a, list_b, 'a');
	}
}

void	first_sort(t_nlist **list_a, t_nlist **list_b, int pos)
{
	int	len;

	len = len_list(list_a);
	if (pos == 1)
	{
		swap(list_a, list_b, 'a');
	}
	else if (pos == 2 && len == 5)
	{
		rotate(list_a, list_b, 'a');
		swap(list_a, list_b, 'a');
	}
	else if ((pos == 3 && len == 5) || (pos == 2 && len == 4))
	{
		rev_rotate(list_a, list_b, 'a');
		rev_rotate(list_a, list_b, 'a');
	}
	else if (pos == 4 || (pos == 3 && len == 4))
		rev_rotate(list_a, list_b, 'a');
	push(list_a, list_b, 'b');
}

void	simple_sort(t_nlist **list_a, t_nlist **list_b)
{
	int	position;

	if (len_list(list_a) == 2)
	{
		swap(list_a, list_b, 'a');
		return ;
	}
	while (len_list(list_a) > 3)
	{
		position = find_min(list_a);
		first_sort(list_a, list_b, position);
	}
	sort_three(list_a, list_b);
	while (*list_b)
		push(list_a, list_b, 'a');
}
