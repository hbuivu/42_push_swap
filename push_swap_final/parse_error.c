/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:09:57 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 11:09:57 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list_a(t_nlist **list_a)
{
	free_list(list_a);
	write (2, "Error\n", 6);
	exit(1);
}

static int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

static int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

void	detect_invalid_entry(char *str, t_nlist **list_a)
{
	int	i;
	int	num_detect;

	i = 0;
	num_detect = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && !is_num(str[i]) && !is_sign(str[i]))
			|| (is_num(str[i]) && is_sign(str[i + 1]))
			|| (is_sign(str[i]) && is_sign(str[i + 1]))
			|| (is_sign(str[i]) && str[i + 1] == ' '))
		{
			free_list_a(list_a);
		}
		if (str[i] >= '0' && str[i] <= '9')
			num_detect++;
		i++;
	}
	if (num_detect == 0)
		free_list_a(list_a);
}

int	detect_duplicate(char *str, t_nlist **list_a)
{
	t_nlist	*curr;
	int		i;

	curr = *list_a;
	i = ft_atoi(str);
	if (!*list_a)
		return (0);
	while (curr)
	{
		if (curr->num == i)
		{
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}
