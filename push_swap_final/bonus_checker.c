/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:20:35 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/14 14:20:35 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

void	clear_buf(char *buf)
{
	int	i;

	i = 0;
	while (i < 5 && buf[i])
	{
		buf[i] = '\0';
		i++;
	}
}

void	free_all(t_nlist **list_a, t_nlist **list_b, char *buf, char c)
{
	if (list_a)
		free_list(list_a);
	if (list_b)
		free_list(list_b);
	if (buf)
		free(buf);
	if (c == 'm')
	{
		write (2, "Malloc error\n", 13);
		exit(1);
	}
	else if (c == 'i')
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	else if (c == 'a')
		return ;
}

void	invalid_move(t_nlist **list_a, t_nlist **list_b, char *buf)
{
	if (buf[0] == '\0')
	{
		if (check_sort(list_a) == 1 && *list_b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_all(list_a, list_b, buf, 'a');
		exit(0);
	}	
	else
		free_all(list_a, list_b, buf, 'i');
}

void	move_array(t_nlist **list_a, t_nlist **list_b, char *buf)
{
	if (ft_strncmp(buf, "sa\n", 4) == 0)
		b_swap(list_a, list_b, 'a');
	else if (ft_strncmp(buf, "sb\n", 4) == 0)
		b_swap(list_a, list_b, 'b');
	else if (ft_strncmp(buf, "ss\n", 4) == 0)
		b_swap(list_a, list_b, 's');
	else if (ft_strncmp(buf, "pa\n", 4) == 0)
		b_push(list_a, list_b, 'a');
	else if (ft_strncmp(buf, "pb\n", 4) == 0)
		b_push(list_a, list_b, 'b');
	else if (ft_strncmp(buf, "ra\n", 4) == 0)
		b_rotate(list_a, list_b, 'a');
	else if (ft_strncmp(buf, "rb\n", 4) == 0)
		b_rotate(list_a, list_b, 'b');
	else if (ft_strncmp(buf, "rr\n", 4) == 0)
		b_rotate(list_a, list_b, 'r');
	else if (ft_strncmp(buf, "rra\n", 5) == 0)
		b_rev_rotate(list_a, list_b, 'a');
	else if (ft_strncmp(buf, "rrb\n", 5) == 0)
		b_rev_rotate(list_a, list_b, 'b');
	else if (ft_strncmp(buf, "rrr\n", 5) == 0)
		b_rev_rotate(list_a, list_b, 'r');
	else
		invalid_move(list_a, list_b, buf);
}

int	main(int argv, char **argc)
{
	char	*buf;
	t_nlist	**list_a;
	t_nlist	**list_b;

	if (argv == 1)
		return (0);
	buf = NULL;
	list_a = parse_entries(argc);
	list_b = (t_nlist **)ft_calloc(1, sizeof(t_nlist *));
	if (!list_b)
		free_all(list_a, list_b, buf, 'm');
	*list_b = NULL;
	buf = (char *)ft_calloc(5, sizeof(char));
	if (!buf)
		free_all(list_a, list_b, buf, 'm');
	while (buf[0] != '\n')
	{
		read(0, buf, 4);
		move_array(list_a, list_b, buf);
		clear_buf(buf);
	}
	return (0);
}
