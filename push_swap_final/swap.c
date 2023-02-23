/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:34:38 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 11:34:39 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_swap(t_nlist **list)
{
	int	temp;

	if (*list == NULL || (*list)->next == NULL || (*list)->next->next == NULL)
		return ;
	temp = (*list)->num;
	(*list)->num = (*list)->next->num;
	(*list)->next->num = temp;
}

void	swap(t_nlist **list_a, t_nlist **list_b, char c)
{
	if (c == 'a')
	{
		run_swap(list_a);
		write (1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		run_swap(list_b);
		write (1, "sb\n", 3);
	}
	else if (c == 's')
	{
		run_swap(list_a);
		run_swap(list_b);
		write (1, "ss\n", 3);
	}
}
