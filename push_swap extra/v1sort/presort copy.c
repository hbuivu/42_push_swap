#include "push_swap.h"

void	reset_dlist(t_dlist *d, t_nlist **list_a)
{
	d->top = *list_a;
	d->bottom = (*list_a)->prev;
	d->t_index = 0;
	d->b_index = len_list(list_a) - 1;
}

void	push_num(t_nlist **list_a, t_nlist **list_b, t_dlist *d, char c)
{
	int	moves;

	if (c == 't')
	{
		moves = d->t_index;
		while (moves-- > 0)
		{
			//*list_b
			//number is between the two pivots
			//num is < subpivot ->number 
			//the next num is > subpivot or the next number is not between two pivots
			// if (*list_b && in_range((*list_b)->num, d) == 1 && (*list_b)->num < d->subpivots[d->i] &&
			// 	((*list_b)->next->num >= d->subpivots[d->i] || in_range((*list_b)->next->num, d) == 0))
			if (*list_b && in_range((*list_b)->num, d, 's') == 1 && in_range((*list_b)->next->num, d, 's') == 0)
				rotate(list_a, list_b, 'r');
			else 
				rotate(list_a, list_b, 'a');
		}
	}
	else if (c == 'b')
	{
		moves = d->len - d->b_index;
		while (moves-- > 0)
			rev_rotate(list_a, list_b, 'a'); //check this logic again bc this should be a???
	}
	//same as above
	// if (*list_b && in_range((*list_b)->num, d) == 1 && (*list_b)->num < d->subpivots[d->i] &&
	// 	((*list_b)->next->num >= d->subpivots[d->i] || in_range((*list_b)->next->num, d) == 0))
	if (*list_b && in_range((*list_b)->num, d, 's') == 1 && in_range((*list_b)->next->num, d, 's') == 0)
		rotate(list_a, list_b, 'b');
	push (list_a, list_b, 'b');
	reset_dlist(d, list_a);
}

void	push_to_b(t_nlist **list_a, t_nlist **list_b, t_dlist *d)
{
	int	moves;
	while (d->t_index <= d->b_index)
	{
		if (in_range(d->top->num, d, 'p') == 1)
			push_num(list_a, list_b, d, 't');
		else if (in_range(d->top->num, d, 'p' == 1))
			push_num(list_a, list_b, d, 'b');
		else 
		{
			d->top = d->top->next;
			d->bottom = d->bottom->prev;
			d->t_index ++;
			d->b_index --;
		}
	}
	// if ((*list_b)->num < d->subpivots[d->i] && (*list_b)->next->num >= d->subpivots[d->i])
	if (in_range((*list_b)->num, d, 's') == 1 && in_range((*list_b)->next->num, d, 's') == 0)
		rotate(list_a, list_b, 'b');
}

void	presort(t_nlist **list_a, t_nlist **list_b, t_dlist *d)
{
	int	buckets;

	buckets = d->buckets;
	while (--buckets > 0)
	{
		push_to_b(list_a, list_b, d);
		reset_dlist(d, list_a);
		d->i++;
		d->j += 2;
	}
	//FOR THE LAST ITERATION, PUSH OVER ALL EXCEPT THREE
	while (len_list(list_a) > 3)
	{
		push(list_a, list_b, 'b');
		// if ((*list_b)->num < d->subpivots[d->i])
		if (in_range((*list_b)->num, d, 's') == 1)
			rotate(list_a, list_b, 'b');
	}
	//sort_three(list_a);
}

