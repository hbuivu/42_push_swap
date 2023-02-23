#include "push_swap.h"

//void	calc_list(t_plist *p)

int	find_max(t_nlist **list_b, t_plist *p)
{
	int		max;
	int		max_position;
	int		position;
	int		beg_num;
	t_nlist	*cur; 

	max = (*list_b)->num;
	max_position = 0;
	position = 1;
	beg_num = (*list_b)->num;
	cur = (*list_b)->next;
	while (cur->num < p->range && cur->num != beg_num) //it's not p->range
	{
		if (max < cur->num)
		{
			max = cur->num;
			max_position = position;
		}
		cur = cur->next;
		position++;
	}
	position = len_list(list_b) - 1;
	cur = (*list_b)->prev;
	while (cur->num < p->range && cur->num != beg_num)
	{
		if (max < cur->num)
		{
			max = cur->num;
			max_position = position;
		}
		cur = cur->prev;
		position--;
	}
	return (max_position);
}

void	push_max(t_nlist **list_a, t_nlist **list_b, t_plist *p)
{
	int	index;
	int	len;
	int	mid;

	index = find_max(list_b, p);
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
		while (len - index > 0)
		{
			rotate(list_a, list_b, 'b');
			index--;
		}	
	}
	push(list_a, list_b, 'a');
}

void	calc_plist(t_nlist **list_a, t_plist *p)
{
	p->top = *list_a;
	p->bottom = (*list_a)->prev;
	p->t_index = 0;
	p->b_index = len_list(list_a) - 1;
	p->tmoves = 0;
	p->bmoves = 1;
	p->min += p->range;
	p->range_max = p->min + p->range;
	p->mid = (p->min + p->range) / 2;
}

void	complex_sort(t_nlist **list_a, t_nlist **list_b)
{
	t_plist	*p;
	int		chunk;
	int		len_list_a;

	p = init_plist(list_a, list_b);
	//instead of defining chunks, experiment with defining based on length of list_a;
	chunk = CHUNKS;
	while (chunk > 0)
	{
		presort(list_a, list_b, p);
		calc_plist(list_a, p);
		chunk --;
	}
}
// sqrt of size and then divide by 2 
// 5 for 100 |||| 11 for 500
// i = 0;
// -l m
// tmp[20]; 19 36 71 100

//       top->value;  <= tmp[pivot[i]]  = 19 &&  tmp[pivot[i+1]]  = 19
// 100


// pivot(0, 10, 20)