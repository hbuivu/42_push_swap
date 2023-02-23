/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entries.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:07:33 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/18 14:45:30 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	detect_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

t_nlist	*create_node(char *str, t_nlist *curr)
{
	t_nlist		*node;
	long long	i;

	i = ft_atoi(str);
	if (i == 3000000000)
	{
		write (2, "Error\n", 7);
		return (NULL);
	}
	node = (t_nlist *)ft_calloc(1, sizeof(t_nlist));
	if (!node)
		return (NULL);
	if (!curr)
		node->prev = NULL;
	else
		node->prev = curr;
	node->next = NULL;
	node->num = (int)i;
	return (node);
}

t_nlist	*add_node(char *str, t_nlist **list_a, t_nlist *curr)
{
	t_nlist	*temp;

	if (detect_duplicate(str, list_a))
	{
		write (2, "Error\n", 6);
		return (NULL);
	}
	temp = create_node(str, curr);
	if (!temp)
		return (NULL);
	if (!*list_a)
	{
		*list_a = temp;
		curr = temp;
		return (curr);
	}
	curr->next = temp;
	curr = curr->next;
	return (curr);
}

t_nlist	*add_split_node(char *str, t_nlist **list_a, t_nlist *curr)
{
	char	**split_list;
	int		i;

	split_list = NULL;
	i = 0;
	if (!detect_space(str))
	{
		curr = add_node(str, list_a, curr);
		if (!curr)
			exit_on_malloc_error(list_a, split_list);
	}
	else
	{
		split_list = ft_split(str, ' ', list_a);
		while (split_list[i])
		{
			curr = add_node(split_list[i], list_a, curr);
			if (!curr)
				exit_on_malloc_error(list_a, split_list);
			i++;
		}
		free_split_list(split_list);
	}
	return (curr);
}

t_nlist	**parse_entries(char **argc)
{
	t_nlist	**list_a;
	t_nlist	*curr;

	list_a = (t_nlist **)ft_calloc(1, sizeof(t_nlist *));
	if (!list_a)
		exit(1);
	*list_a = NULL;
	curr = NULL;
	argc++;
	while (*argc)
	{
		detect_invalid_entry(*argc, list_a);
		curr = add_split_node(*argc, list_a, curr);
		argc++;
	}
	(*list_a)->prev = curr;
	curr->next = *list_a;
	return (list_a);
}
