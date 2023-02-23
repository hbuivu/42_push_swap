#include "push_swap.h"

int	check_top(t_nlist **list_a, t_nlist **list_b, t_plist *p)
{
	if (p->top->num >= p->min && p->top->num <= p->range_max)
	{
		if (*list_b && p->tmoves == 0 && ((*list_b)->num < p->mid && (*list_b)->next->num >= p->mid))
			rotate(list_a, list_b, 'b');
		p->b_index -= (p->tmoves + 1); //b_index is pushed by tmoves amt + 1 <- to account for decrease in len
		while(p->tmoves > 0)
		{
			if (*list_b && (*list_b)->num < p->mid && (*list_b)->next->num >= p->mid)
				rotate(list_a, list_b, 'r'); 
			else
				rotate(list_a, list_b, 'a');
			p->tmoves--;
		}
		push(list_a, list_b, 'b');
		p->bmoves = len_list(list_a) - p->b_index;
		p->top = *list_a;
		p->t_index = 0;
		//p->tmoves = 0;
		return (1);
	}
	return (0);
}

int	check_bottom(t_nlist **list_a, t_nlist **list_b, t_plist *p)
{
	if (p->bottom->num >= p->min && p->bottom->num <= p->min + p->range)
	{
		p->t_index += (p->bmoves - 1); //can't be put in while loop, bc there is one extra rra to bring the pushed number to top. therefore, p->moves - 1;
		//check if b needs to be rotated
		if (*list_b && (*list_b)->num < p->mid && (*list_b)->next->num >= p->mid)
			rotate(list_a, list_b, 'b');
		while(p->bmoves > 0)
		{
			rev_rotate(list_a, list_b, 'a');
			p->bmoves--;
		}
		push(list_a, list_b, 'b');
		p->tmoves = p->t_index;
		p->bottom = (*list_a)->prev;
		p->b_index = len_list(list_a) - 1;
		p->bmoves = 1;
		return (1);
	}
	return (0);
}

// void	mod_plist(t_plist *p, char c)
// {
// 	if (c == 'x')
// 		return ;
// 	if (c == 't' || c == 'a')
// 	{
// 		p->top = p->top->next;
// 		p->t_index++;
// 		p->tmoves++;
// 	}
// 	if (c == 'b' || c == 'a')
// 	{
// 		p->bottom = p->bottom->prev;
// 		p->b_index--;
// 		p->bmoves++;
// 	}
// }

// void	presort(t_nlist **list_a, t_nlist **list_b, t_plist *p)
// {
// 	char	c;

// 	c = 'x';
// 	while(p->t_index <= p->b_index)
// 	{
// 		if (p->tmoves < p->bmoves)
// 		{
// 			if (check_top(list_a, list_b, p) == 0)
// 				c = 't';
// 		}
// 		else if (p->tmoves > p->bmoves)
// 		{
// 			if (check_bottom(list_a, list_b, p) == 0)
// 				c = 'b';
// 		}
// 		else
// 		{
// 			if (check_top(list_a, list_b, p) == 0 || check_bottom(list_a, list_b, p) == 0) //if first or statement is evaluated, is the second evaluated?
// 				c = 'a';
// 		}
// 		mod_plist(p, c);
// 	}
// 	if (((*list_b)->num < p->mid && (*list_b)->next->num >= p->mid))
// 		rotate(list_a, list_b, 'b');
// }

void	presort(t_nlist **list_a, t_nlist **list_b, t_plist *p)
{
	while(p->t_index <= p->b_index)
	{
		if (p->tmoves < p->bmoves)
		{
			if (check_top(list_a, list_b, p) == 0)
			{
				p->top = p->top->next;
				p->t_index++;
				p->tmoves++;
			}
		}
		else if (p->tmoves > p->bmoves)
		{
			if (check_bottom(list_a, list_b, p) == 0)
			{
				p->bottom = p->bottom->prev;
				p->b_index--;
				p->bmoves++;
			}
		}
		else
		{
			if (check_top(list_a, list_b, p) == 0 || check_bottom(list_a, list_b, p) == 0) //if first or statement is evaluated, is the second evaluated?
			{
				p->top = p->top->next;
				p->bottom = p->bottom->prev;
				p->t_index++;
				p->b_index--;
				p->bmoves++;
				p->tmoves++;
			}
			//mysteriously, the results change a bit if I use 2 if statements
		}
	}
	if (((*list_b)->num < p->mid && (*list_b)->next->num >= p->mid))
			rotate(list_a, list_b, 'b');
}