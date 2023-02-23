#include "push_swap.h"

void	populate_minmax(t_nlist **list_a, t_plist *p)
{
	int		head;
	int		min;
	int		max;
	t_nlist	*cur;

	head = (*list_a)->num;
	min = (*list_a)->num;
	max = (*list_a)->num;
	cur = (*list_a)->next;
	while (cur->num != head)
	{
		if (cur->num < min)
			min = cur->num;
		if (cur->num > max)
			max = cur->num;
		cur = cur->next;	
	}
	p->min = min;
	p->max = max;
}

t_plist	*init_plist(t_nlist **list_a, t_nlist **list_b)
{
	t_plist	*p;
	
	p = (t_plist *)ft_calloc(1, sizeof(t_plist));
	if (!p)
	{
		free_list(list_a);
		free_list(list_b);
		write (1, "malloc error\n", 13);
		exit(-1);
	}
	p->top = *list_a;
	p->bottom = (*list_a)->prev;
	p->t_index = 0;
	p->b_index = len_list(list_a) - 1;
	p->tmoves = 0;
	p->bmoves = 1;
	populate_minmax(list_a, p); 
	p->range = ((p->max - p->min) / CHUNKS) + 1;
	p->range_max = p->min + p->range;
	p->mid = (p->min + p->range) / 2;
	return(p);
}