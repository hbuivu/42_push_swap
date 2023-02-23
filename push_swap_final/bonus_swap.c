/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:34:38 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 16:21:41 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

void	run_swap(t_nlist **list)
{
	int	temp;

	if (*list == NULL || (*list)->next == NULL || (*list)->next->next == NULL)
		return ;
	temp = (*list)->num;
	(*list)->num = (*list)->next->num;
	(*list)->next->num = temp;
}

void	b_swap(t_nlist **list_a, t_nlist **list_b, char c)
{
	if (c == 'a')
	{
		run_swap(list_a);
	}
	else if (c == 'b')
	{
		run_swap(list_b);
	}
	else if (c == 's')
	{
		run_swap(list_a);
		run_swap(list_b);
	}
}
