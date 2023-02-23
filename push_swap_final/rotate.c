/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:34:10 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 15:44:38 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_nlist **list_a, t_nlist **list_b, char c)
{
	if (c == 'a' && *list_a)
	{
		if (*list_a)
			*list_a = (*list_a)->next;
		write(1, "ra\n", 3);
	}
	if (c == 'b' && *list_b)
	{
		if (*list_b)
			*list_b = (*list_b)->next;
		write(1, "rb\n", 3);
	}
	if (c == 'r' && (*list_a || *list_b))
	{
		if (*list_a)
			*list_a = (*list_a)->next;
		if (*list_b)
			*list_b = (*list_b)->next;
		write(1, "rr\n", 3);
	}
	return ;
}

void	rev_rotate(t_nlist **list_a, t_nlist **list_b, char c)
{
	if (c == 'a')
	{
		if (*list_a)
			*list_a = (*list_a)->prev;
		write(1, "rra\n", 4);
	}
	if (c == 'b')
	{
		if (*list_b)
			*list_b = (*list_b)->prev;
		write(1, "rrb\n", 4);
	}
	if (c == 'r')
	{	
		if (*list_a)
			*list_a = (*list_a)->prev;
		if (*list_b)
		*list_b = (*list_b)->prev;
		write(1, "rrr\n", 4);
	}
}
