#include "push_swap.h"

// int	find_max(t_nlist **list_b, t_dlist *d)
// {
// 	int		max;
// 	int		max_position;
// 	int		position;
// 	int		beg_num;
// 	t_nlist	*cur; 

// 	max = (*list_b)->num;
// 	max_position = 0;
// 	position = 1;
// 	beg_num = (*list_b)->num;
// 	cur = (*list_b)->next;
// 	while (in_range(cur->num, d))
// 	{
// 		if (max < cur->num)
// 		{
// 			max = cur->num;
// 			max_position = position;
// 		}
// 		cur = cur->next;
// 		position++;
// 	}
// 	position = len_list(list_b) - 1;
// 	cur = (*list_b)->prev;
// 	while (in_range(cur->num, d))
// 	{
// 		if (max < cur->num)
// 		{
// 			max = cur->num;
// 			max_position = position;
// 		}
// 		cur = cur->prev;
// 		position--;
// 	}
// 	return (max_position);
// }

int	find_max(t_nlist **list_b, t_dlist *d)
{
	int		max;
	int		max_position;
	int		position;
	int		len;
	t_nlist	*cur; 

	max = (*list_b)->num;
	max_position = 0;
	position = 1;
	cur = (*list_b)->next;
	len = len_list(list_b);
	while (position < len)
	{
		if (max < cur->num)
		{
			max = cur->num;
			max_position = position;
		}
		cur = cur->next;
		position++;
	}
	return (max_position);
}

void	push_max(t_nlist **list_a, t_nlist **list_b, t_dlist *d)
{
	int	index;
	int	len;
	int	mid;
	int	moves;

	index = find_max(list_b, d);
	len = len_list(list_b);
	mid = len / 2;
	if (index < mid)
	{
		while (index > 0)
		{
			rotate(list_a, list_b, 'b');
			index--;
		}
	}
	else
	{
		moves = len - index;
		while (moves > 0)
		{
			rev_rotate(list_a, list_b, 'b');
			moves--;
		}	
	}
	push(list_a, list_b, 'a');
}

void	complex_sort(t_nlist **list_a, t_nlist **list_b, t_dlist *d)
{
	int	buckets;

	buckets = d->buckets;
	presort(list_a, list_b, d);
	while (*list_b)
		push_max(list_a, list_b, d);
}