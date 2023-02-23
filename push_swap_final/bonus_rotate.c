/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:34:10 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 16:21:34 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

void	b_rotate(t_nlist **list_a, t_nlist **list_b, char c)
{
	if (c == 'a' && *list_a)
	{
		if (*list_a)
			*list_a = (*list_a)->next;
	}
	if (c == 'b' && *list_b)
	{
		if (*list_b)
			*list_b = (*list_b)->next;
	}
	if (c == 'r' && (*list_a || *list_b))
	{
		if (*list_a)
			*list_a = (*list_a)->next;
		if (*list_b)
			*list_b = (*list_b)->next;
	}
	return ;
}

void	b_rev_rotate(t_nlist **list_a, t_nlist **list_b, char c)
{
	if (c == 'a')
	{
		if (*list_a)
			*list_a = (*list_a)->prev;
	}
	if (c == 'b')
	{
		if (*list_b)
			*list_b = (*list_b)->prev;
	}
	if (c == 'r')
	{	
		if (*list_a)
			*list_a = (*list_a)->prev;
		if (*list_b)
		*list_b = (*list_b)->prev;
	}
}
