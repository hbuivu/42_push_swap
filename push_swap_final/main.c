/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:35:01 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/16 19:43:00 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_nlist **list_a, t_nlist **list_b, t_data *d)
{
	int	len;

	len = len_list(list_a);
	if (check_sort(list_a) || len_list(list_a) == 1)
		return ;
	if (len <= 5)
		simple_sort(list_a, list_b);
	else
		complex_sort(list_a, list_b, d);
}

void	free_all(t_nlist **list_a, t_nlist **list_b, t_data *d)
{
	free_list(list_a);
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
}

int	main(int argv, char **argc)
{
	t_nlist	**list_a;
	t_nlist	**list_b;
	t_data	*d;

	if (argv == 1)
		return (0);
	list_a = parse_entries(argc);
	list_b = (t_nlist **)ft_calloc(1, sizeof(t_nlist *));
	if (!list_b)
	{
		free_list(list_a);
		return (-1);
	}
	*list_b = NULL;
	d = init_dlist(list_a, list_b);
	push_swap(list_a, list_b, d);
	free_all(list_a, list_b, d);
	return (0);
}
