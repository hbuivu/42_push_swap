/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:18:00 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/18 14:45:30 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_nlist **list)
{
	t_nlist	*next;
	t_nlist	*temp;

	if (list && *list)
	{
		next = (*list)->next;
		while (next && next != *list)
		{
			temp = next;
			next = next->next;
			free(temp);
		}
		free(*list);
	}
	if (list)
		free(list);
	return ;
}

void	free_split_list(char **split_list)
{
	int	i;

	i = 0;
	while (split_list[i])
	{
		free(split_list[i]);
		i++;
	}
	free(split_list);
}

void	exit_on_malloc_error(t_nlist **list_a, char **split_list)
{
	if (list_a)
		free_list(list_a);
	if (split_list)
		free_split_list(split_list);
	exit(1);
}

void	free_all_three(t_nlist **list_a, t_nlist **list_b, t_data *d)
{
	write (2, "malloc error\n", 13);
	if (list_a)
		free_list(list_a);
	if (list_b)
		free_list(list_b);
	if (d)
	{
		if (d->pivots)
			free(d->pivots);
		if (d->subpivots)
			free(d->subpivots);
		if (d->allpivots)
			free(d->allpivots);
		free(d);
	}
	exit(1);
}

void	free_all_four(t_nlist **list_a, t_nlist **list_b, t_data *d, t_mlist *m)
{
	if (m)
		free(m);
	free_all_three(list_a, list_b, d);
}
