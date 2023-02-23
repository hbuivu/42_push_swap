#include "push_swap.h"

void	calc_plist(p)
{
	//recalc min;
	//recalc mid;
	//reset everything else;
	//note: keep min constant but intro range_min that changes
}

void	check_num(list_a, list_b, int num)
{
	if (num < *list_a->num)
		//push
	else if (num > *list_a->num && num < (*list_a)->next->num)
		//push and swap
	else if (num > (*list_a)->prev->num)
		//push and rotate
	else
		//
}

void	complex_sort(t_nlist **list_a, t_nlist **list_b)
{
	t_plist	*p;
	int		chunk;
	int		len_list_a;

	p = init_plist(list_a, list_b);
	//instead of defining chunks, experiment with defining based on length of list_a;
	chunk = CHUNKS;
	while (chunk > 1)
	{
		push_num(list_a, list_b, p);
		calc_plist(p);
		chunk --;
	}

	len_list_a = len_list(list_a);
	while (len_list_a > 3)
	{
		push(list_a, list_b, 'b');
		if ((*list_b)->num < p->mid)
			rotate(list_a, list_b, 'b');
		len_list_a--;
	}

	sort_three(list_a, list_b);
	//while (list b is not empty)
		//iterate through each range top and bottom
	
	//check number in top 3 and bottom 3 
	//what position do they fall into and how many moves does it take to insert?
	//a
	

}
