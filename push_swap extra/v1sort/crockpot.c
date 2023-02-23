	// // *********TESTING LINKED LIST**************
	// t_nlist *curr;

	// curr = *list_a;
	// while (curr)
	// {
	// 	printf("----\n");
	// 	if (curr->prev)
	// 		printf("prev num: %i\n", curr->prev->num);
	// 	printf("curr num: %i\n", curr->num);
	// 	if (curr->next)
	// 		printf("next num: %i\n", curr->next->num);
	// 	curr = curr->next;
	// }

	// //******TESTING detect_invalid_entry********
	// int i = 1;
	// if (argv > 1)
	// {
	// 	while (i < argv)
	// 	{
	// 		detect_invalid_entry(argc[i]);
	// 		i++;
	// 	}
	// }


	//take first element from push from ->transfer to temp var
	//put first element on temp node
	//relink 2nd element with end
	//free temp node
	
	//create a node with the temp var
	//free_list(a and b) if malloc doesn't work
	//node->next = *push_to
	//node->prev = *push_to ->prev;
	//*push_to->prev->next = node;
	//*push_to->prev = node;

// void	complex_sort(t_nlist **list_a, t_nlist **list_b)
// {
// 	int	min;
// 	int	max;
// 	int	range;
// 	int	len;
// 	int	limit;
// 	t_nlist	*a;
	
// 	min = find_min(list_a);
// 	max = find_max(list_a);
// 	range = ((max - min) / 5); //test 5 for 100 for now, does this need to be rounded up?
// 	limit = min + range
// 	//go through the list - if number falls in bucket push to b, else rotate list_a
// 	//also while pushing, pre_sort b??
// 	while (len_list(list_a) > 3) //change this bc this does not guarantee there is 3 left. how to leave 3 in group a
// 	{
// 		len = len_list(list_a);
// 		a = *list_a;
// 		while (len > 0)
// 		{
// 			if (a->num < limit) //at the last iteration it needs to be <= limit, unless you leave 3 in a
// 				push(list_a, list_b, 'b');
// 			else 
// 				rotate(list_a, list_b, 'a');
// 			a = a->next;
// 			len--;
// 		}
// 		min = limit;
// 		limit = min + range;
// 	}
// 	sort_three(list_a, list_b);

	

// }

//***TEST ROTATION AND POINTERS*****//
	// t_nlist *top;
	// t_nlist *bottom;

	// top = *list_a;
	// bottom = (*list_a)->prev;
	// printf("top: %i bottom: %i\n", top->num, bottom->num);
	// print_list(list_a, 'a');
	// //push index 2
	// rotate(list_a, list_b, 'a');
	// rotate(list_a, list_b, 'a');
	// push(list_a, list_b, 'b');
	// print_list(list_a, 'a');
	// top = top->next;
	// bottom = bottom->prev;
	// printf("top->next: %i bottom->prev: %i\n", top->num, bottom->num);

// void	populate_minmax(t_nlist **list, t_plist *p)
// {
// 	int		head;
// 	int		min;
// 	int		max;
// 	t_nlist	*cur;

// 	head = (*list)->num;
// 	min = (*list)->num;
// 	max = (*list)->num;
// 	cur = (*list)->next;
// 	while (cur->num != head)
// 	{
// 		if (cur->num < min)
// 			min = cur->num;
// 		if (cur->num > max)
// 			max = cur->num;
// 		cur = cur->next;	
// 	}
// 	p->min = min;
// 	p->max = max;
// }

// t_plist	*init_plist(t_nlist **list_a, t_nlist **list_b)
// {
// 	t_plist	*plist;
	
// 	plist = (t_plist *)ft_calloc(1, sizeof(t_plist));
// 	if (!plist)
// 	{
// 		free_list(list_a);
// 		free_list(list_b);
// 		//write malloc error;
// 		exit(-1);
// 	}
// 	plist->top = *list_a;
// 	plist->bottom = (*list_a)->prev;
// 	plist->t_index = 0;
// 	plist->b_index = len_list(list_a) - 1;
// 	plist->tmoves = 0;
// 	plist->bmoves = 1;
// 	populate_minmax(list_a, plist);
// 	plist->range = ((plist->max - plist->min) / CHUNKS) + 1;
// 	return(plist);
// }

// int	check_top(t_nlist **list_a, t_nlist **list_b, t_plist *p)
// {
// 	if (p->top->num >= p->min && p->top->num < p->min + p->range)
// 	{
// 		while(p->tmoves > 0)
// 		{
// 			rotate(list_a, list_b, 'a');
// 			p->b_index--;
// 			p->tmoves--;
// 		}
// 		push(list_a, list_b, 'b');
// 		p->top = *list_a;
// 		p->t_index = 0;
// 		p->tmoves = 0; //this is redundant but put here to remember
// 		return (1);
// 	}
// 	else
// 	{
// 		p->top = p->top->next;
// 		p->t_index++;
// 		p->tmoves++;
// 	}
// 	return (0);
// }

// int	check_bottom(t_nlist **list_a, t_nlist **list_b, t_plist *p)
// {
// 	if (p->bottom->num >= p->min && p->bottom->num < p->min + p->range)
// 	{
// 		while(p->bmoves > 0)
// 		{
// 			rev_rotate(list_a, list_b, 'a');
// 			p->t_index++;
// 			p->bmoves--;
// 		}
// 		push(list_a, list_b, 'b');
// 		p->bottom = (*list_a)->prev;
// 		p->b_index = len_list(list_a) - 1;
// 		p->bmoves = 1;
// 		return (1);
// 	}
// 	else
// 	{
// 		p->bottom = p->bottom->prev;
// 		p->b_index++;
// 		p->bmoves++;
// 	}
// 	return (0);
// }

// void	push_num(t_nlist **list_a, t_nlist **list_b)
// {
// 	t_plist	*p;

// 	p = init_plist(list_a, list_b);
// 	print_plist(p);
// 	int i = 5;
// 	while(p->t_index <= p->b_index)
// 	while(i)
// 	{
// 		if (p->tmoves < p->bmoves)
// 		{
// 			printf("top checked\n");
// 			check_top(list_a, list_b, p);
// 			//if !check_top
// 				// p->top = p->top->next;
// 				// p->t_index++;
// 				// p->tmoves++;
// 		}
// 		else if (p->tmoves > p->bmoves)
// 		{
// 			printf("bottom checked\n");
// 			check_bottom(list_a, list_b, p);
// 			// if !check_bottom
// 				// p->bottom = p->bottom->prev;
// 				// p->b_index++;
// 				// p->bmoves++;

// 		}
// 		else
// 		{
// 			printf("moves equal\n");
// 			if (!check_top(list_a, list_b, p)); //this moved the index twice, so need to rethink this part
// 			{
// 				printf("didn't find anything on top, checking bottom\n");
// 				check_bottom(list_a, list_b, p);
// 			}
// 			//if !check_top
// 				//if !check_bottom
// 					//move pointers
// 					//move indexes
// 		}
// 		print_plist(p);
// 		print_list(list_a, 'a');
// 		print_list(list_b, 'b');
// 		i--;
// 	}

// }


// int	count_smalls(t_nlist **list_b, t_plist *p)
// {
// 	int		len;
// 	int		count;
// 	t_nlist	*cur;

// 	if (!*list_b)
// 		return (0);
// 	len = len_list(list_b);
// 	count = 0;
// 	cur = *list_b;
// 	while (len > 0)
// 	{
// 		if (cur->num >= p->mid)
// 			break;
// 		if (cur->num < p->mid)
// 			count++;
// 		len--;
// 		cur = cur->next;
// 	}
// 	if (count == len_list(list_b))
// 		return (0);
// 	return (count);
// }

// int	check_top(t_nlist **list_a, t_nlist **list_b, t_plist *p)
// {
// 	int	rot;

// 	if (p->top->num >= p->min && p->top->num < p->min + p->range)
// 	{
// 		p->b_index -= (p->tmoves + 1); //b_index is pushed by tmoves amt + 1 <- to account for decrease in len
// 		if (p->top->num >= p->mid)
// 		{
// 			rot = count_smalls(list_b, p) - p->tmoves;
// 			if (rot > 0)
// 			{
// 				while (rot > 0)
// 				{
// 					rotate(list_a, list_b, 'b');
// 					rot--;
// 				}
// 			}
// 		}
// 		while(p->tmoves > 0)
// 		{
// 			if ((*list_b)->num < p->mid)
// 				rotate(list_a, list_b, 'r'); //make sure r and rr doesn't rotate lists of one
// 			else
// 				rotate(list_a, list_b, 'a');
// 			p->tmoves--;
// 		}
// 		push(list_a, list_b, 'b');
// 		p->bmoves = len_list(list_a) - p->b_index;
// 		p->top = *list_a;
// 		p->t_index = 0;
// 		p->tmoves = 0; //this is redundant but put here to remember
// 		return (1);
// 	}
// 	return (0);
// }

// int	check_bottom(t_nlist **list_a, t_nlist **list_b, t_plist *p)
// {
// 	int rot;

// 	if (p->bottom->num >= p->min && p->bottom->num < p->min + p->range)
// 	{
// 		p->t_index += (p->bmoves - 1); //can't be put in while loop, bc there is one extra rra to bring the pushed number to top. therefore, p->moves - 1;
// 		if (p->bottom->num >= p->mid)
// 		{
// 			rot = count_smalls(list_b, p);
// 			if (rot > 0)
// 			{
// 				while (rot > 0)
// 				{
// 					rotate(list_a, list_b, 'b');
// 					rot--;
// 				}
// 			}
// 		}
// 		while(p->bmoves > 0)
// 		{
// 			rev_rotate(list_a, list_b, 'a');
// 			p->bmoves--;
// 		}
// 		push(list_a, list_b, 'b');
// 		p->tmoves = p->t_index;
// 		p->bottom = (*list_a)->prev;
// 		p->b_index = len_list(list_a) - 1;
// 		p->bmoves = 1;
// 		return (1);
// 	}
// 	return (0);
// }

// int	find_min_num(t_nlist **list)
// {
// 	int		head;
// 	int		min;
// 	t_nlist	*cur;

// 	head = (*list)->num;
// 	min = (*list)->num;
// 	cur = (*list)->next;
// 	while (cur->num != head)
// 	{
// 		if (cur->num < min)
// 			min = cur->num;
// 		cur = cur->next;	
// 	}
// 	return (min);
// }

// int find_max(t_nlist **list)
// {
// 	int		head;
// 	int		max;
// 	t_nlist	*cur;

// 	head = (*list)->num;
// 	max = (*list)->num;
// 	cur = (*list)->next;
// 	while (cur->num != head)
// 	{
// 		if (cur->num > max)
// 			max = cur->num;
// 		cur = cur->next;	
// 	}
// 	return (max);
// } //can i combine this and put min and max into a struct?

// int	in_range(int num, int min, int range)
// {
// 	if (num >= min && num < min + range)
// 		return (1);
// 	return (0);
// }

// void	push_num(t_nlist **list_a, t_nlist **list_b, int min, int range)
// {
// 	t_nlist	*top;
// 	t_nlist	*bottom;
// 	int		top_position;
// 	int		bottom_position;
// 	int		moves;
	
// 	top = *list_a;
// 	bottom = (*list_a)->prev;
// 	top_position = 0;
// 	bottom_position = len_list(list_a) - 1;
// 	while (top_position <= bottom_position)
// 	{
// 		if (in_range(top->num, min, range)) //push top
// 		{
// 			moves = top_position;
// 			while (moves > 0)
// 			{
// 				rotate(list_a, list_b, 'a');
// 				bottom_position--;
// 				moves--;
// 			}
// 			push(list_a, list_b, 'b');
// 			top = *list_a;
// 			top_position = 0;
// 			bottom = bottom->prev;
// 			bottom_position--;
// 		}
// 		else if (in_range(bottom->num, min, range)) //push bottom
// 		{
// 			moves = len_list(list_a) - bottom_position;
// 			while (moves > 0)
// 			{
// 				rev_rotate(list_a, list_b, 'a');
// 				top_position++;
// 				moves--;
// 			}
// 			push(list_a, list_b, 'b');
// 			bottom = (*list_a)->prev;
// 			bottom_position = len_list(list_a) - 1;
// 			top = top->next;
// 			top_position++;
// 		}
// 		else
// 		{
// 			top_position++;
// 			bottom_position--;
// 			top = top->next;
// 			bottom = bottom->prev;
// 		}
		
// 	}
// }

//in list_a push_num
//meanwhile in list_b
	//find mid number in range
	//sort top and bottom of b based on that number

// t_plist	*init_plist(t_nlist **list_a, t_nlist **list_b)
// {
// 	t_plist	*plist;
	
// 	plist = (t_plist *)ft_calloc(1, sizeof(t_plist));
// 	if (!plist)
// 	{
// 		free_list(list_a);
// 		free_list(list_b);
// 		//write malloc error;
// 		exit(-1);
// 	}
// 	plist->top = *list_a;
// 	plist->bottom = (*list_a)->prev;
// 	plist->t_index = 0;
// 	plist->b_index = len_list(list_a) - 1;
// 	plist->tmoves = 0;
// 	plist->bmoves = 1;
// 	populate_minmax(list_a, plist);
// 	plist->range = ((plist->max - plist->min) / CHUNKS) + 1;
// 	plist->mid = (plist->min + plist->range) / 2;
// 	return(plist);
// }

// void	presort(t_nlist **list_a, t_nlist **list_b, t_plist *p)
// {
// 	while(p->t_index <= p->b_index)
// 	{
// 		if (p->tmoves < p->bmoves)
// 		{
// 			if (check_top(list_a, list_b, p) == 0)
// 			{
// 				p->top = p->top->next;
// 				p->t_index++;
// 				p->tmoves++;
// 			}
// 		}
// 		else if (p->tmoves > p->bmoves)
// 		{
// 			if (check_bottom(list_a, list_b, p) == 0)
// 			{
// 				p->bottom = p->bottom->prev;
// 				p->b_index--;
// 				p->bmoves++;
// 			}
// 		}
// 		else
// 		{
// 			if (check_top(list_a, list_b, p) == 0 || check_bottom(list_a, list_b, p) == 0) //if first or statement is evaluated, is the second evaluated?
// 			{
// 				p->bottom = p->bottom->prev;
// 				p->top = p->top->next;
// 				p->b_index--;
// 				p->t_index++;
// 				p->bmoves++;
// 				p->tmoves++;
// 			}
// 			//mysteriously, the results change a bit if I use 2 if statements
// 		}
// 	}
// 	if (((*list_b)->num < p->mid && (*list_b)->next->num >= p->mid))
// 			rotate(list_a, list_b, 'b');
// }

// typedef struct position_list
// {
// 	t_nlist	*top;
// 	t_nlist	*bottom;
// 	int		t_index; 
// 	int		b_index;
// 	int		tmoves;
// 	int		bmoves;
// 	int		min;
// 	int		max;
// 	int		range;
// 	int		range_max;
// 	int		mid;
// }	t_plist;

//start out with pivots as follows
	//range = max - min / buckets
	//bucket_len = len_list(list_a) / buckets;
	//[min, min + (i)range, ...., max + 1];
	//create an array of size len of list;
	//check first bucket in array to see if it falls withing +-5 of bucket len;
	//if it does -> done, don't need to fix pivots
	
	//if it does not, sort bucket 
	//if too large -
		//truncate at bucket len, and note down that pivot
		//push remaining numbers back to list
		//recalculate range with remaining numbers and refill out pivot array 
	//if too small - 
		//push over other numbers
	//repeat last three steps from above

// void	populate_range(t_nlist ** list_a, t_nlist **list_b, t_dlist *d)
// {
// 	int	r;
// 	int	i;

// 	d->range = (int *)ft_calloc(sizeof(int), d->buckets + 1);
// 	if (!d->range)
// 	{
// 		free_list(list_a);
// 		free_list(list_b);
// 		free(d);
// 		write (1, "malloc error\n", 13);
// 	}
// 	d->range[0] = d->min;
// 	d->range[d->buckets] = d->max;
// 	i = 1;
// 	r = (d->max - d->min) / d->buckets;
// 	while (i < buckets)
// 		d->range[i++] = find_range(list_a, d, r, i); 
// }

// int	find_range(t_nlist **list_a, t_dlist *d, int r, int i, )
// {
// 	int		test_range;
// 	int		list_len;
// 	int		count;
// 	t_nlist	*cur;

// 	test_range = d->range[i - 1] + r;
// 	bucket_len = d->len / d->buckets;
// 	list_len = d->len;
// 	while (list_len > 0)
// 		if ()

// }



// void	find_pivots(t_dlist *d, t_nlist **list_a)
// {
// 	int		range;
// 	int		bucket_len;
// 	int		bucket[d->len];
// 	int		i;
// 	int		j;
// 	t_nlist	*cur;

// 	range = ((d->max - d->min) / d->buckets) + 1;
// 	bucket_len = d->len / d->buckets;
// 	cur = *list_a;
// 	i = 0;
// 	//fill bucket with 0s
// 	while (i < d->len)
// 		bucket[i++] = 0;
// 	//starting pivots
// 	i = 0;
// 	while (i <= d->buckets)
// 		d->pivots[i++] = d->min + (i * range);
// 	//filling out first bucket
// 	i = 0;
// 	j = 0;
// 	while (j < d->len)
// 	{
// 		if (cur->num >= d->pivots[i] && cur->num < d->pivots[i + 1])
// 		{
// 			bucket[i] = cur->num;
// 			i++;
// 		}
// 		j++;
// 	}
// 	//check if bucket is approx correct length
// 	if (i >= bucket_len - 5 && i <= bucket_len + 5)
// 		return ;

// }

// t_plist	*init_plist(t_nlist **list_a, t_nlist **list_b)
// {
// 	t_plist	*p;
	
// 	p = (t_plist *)ft_calloc(1, sizeof(t_plist));
// 	if (!p)
// 	{
// 		free_list(list_a);
// 		free_list(list_b);
// 		write (1, "malloc error\n", 13);
// 		exit(-1);
// 	}
// 	p->top = *list_a;
// 	p->bottom = (*list_a)->prev;
// 	p->t_index = 0;
// 	p->b_index = len_list(list_a) - 1;
// 	p->tmoves = 0;
// 	p->bmoves = 1;
// 	populate_minmax(list_a, p); 
// 	p->range = ((p->max - p->min) / CHUNKS) + 1;
// 	p->range_max = p->min + p->range;
// 	p->mid = (p->min + p->range) / 2;
// 	return(p);
// }

// void	push_to_b(t_nlist **list_a, t_nlist **list_b, t_dlist *d, int i)
// {
// 	int	moves;
// 	while (d->t_index >= d->b_index)
// 	{
// 		if (d->top->num >= d->pivots[d->i] && d->top->num < d->pivots[d->i + 1])
// 		{
// 			moves = d->t_index;
// 			while (moves-- > 0)
// 			{
// 				if (*list_b && (*list_b)->num < d->subpivots[i + 1] && (*list_b)->next->num >= d->subpivots[i + 1])
// 					rotate(list_a, list_b, 'r');
// 				else 
// 					rotate(list_a, list_b, 'a');
// 			}
// 			if (*list_b && (*list_b)->num < d->subpivots[i + 1] && (*list_b)->next->num >= d->subpivots[i + 1])
// 				rotate(list_a, list_b, 'r');
// 			push (list_a, list_b, 'b');
// 			reset_dlist(d);
// 		}
// 		else if (d->bottom->num >= d->pivots[d->i] && d->bottom->num < d->pivots[d->i + 1])
// 		{
// 			moves = d->len - d->b_index;
// 			while (moves-- > 0)
// 				rev_rotate(list_a, list_b, 'b');
// 			if (*list_b && (*list_b)->num < d->subpivots[i + 1] && (*list_b)->next->num >= d->subpivots[i + 1])
// 				rotate(list_a, list_b, 'r');
// 			push(list_a, list_b, 'b');
// 			reset_dlist(d);
// 		}
// 		else 
// 		{
// 			d->top = d->top->next;
// 			d->bottom = d->bottom->prev;
// 			d->t_index ++;
// 			d->b_index --;
// 		}
// 	}
// }

// /phase 1
	
// 	moves = moves_a + moves_b
// 	//moves_b
// 	if(index_b > mid_b)
// 		moves_b = len_b - index_b //rrb
// 	else
// 		moves_b = index_b; // rb
// 	//moves_a
// 	if (index_a > mid_a)
// 		moves_a = len_a - index_a; //rra
// 	else
// 		moves_a = index_a; //ra
	
// 	push a;
// 	phase 2
// 	//move back whatever was pushed in a
// 	while num < top and num > bottom
// 		repeat above steps to find spot and insert
// 	phase 3
// 	if (index_a > mid_a)
// 		while (moves_a)
// 			ra
// 	else
// 		while(moves_a)
// 			rra;

int	calc_moves(int num, int index_b, t_nlist **list_a)
{
	int	index_a;
	int	mid_a;
	int	mid_b;
	int	len_a;
	int	len_b;
	int	moves_a;
	int	moves_b;
	int	moves;

	index_a = find_index(num, list_a); //this will need to be adjusted for a cut triangle if it falls in the bottom
	len_a = len_list(list_a);
	len_b = len_list(list_b);
	mid_a = (len_a / 2) - 1;
	mid_b = (len_b / 2) - 1;
	if (index_a > mid_a && index_b > mid_b)
	{
		moves_a = len_a - index_a;
		moves_b = len_b - index_b;
		if (moves_a >= moves_b)
			moves = moves_a;
		else
			moves = moves_b;
	}
	else if (index_a <= mid_a && index_b <= mid_b)
	{
		moves_a = index_a;
		moves_b = index_b;
		if (moves_a >= moves_b)
			moves = moves_a;
		else
			moves = moves_b;
	}
	else if(index_a > mid_a && index_b <= mid_b)
	{
		moves_a = len_a - index_a;
		moves_b = index_b;
		moves = moves_a + moves_b;
	}
	else if (index_a <= mid_a && index_b > mid_b)
	{
		moves_a = index_a;
		moves_b = len_b - index_b;
		moves = moves_a + moves_b;
	}
	return (moves);
}

void	complex_sort(t_nlist **list_a, t_nlist **list_b, t_dlist *d)
{
	t_nlist *cur;
	t_mlist	*m;
	int		i;
	int		moves;
	
	cur = *list_b;
	i = 0;
	m = (t_mlist *)ft_calloc(1, sizeof(t_mlist));
	if (!m)
		free_all(list_a, list_b, d); //check this later
	m->min_move = calc_moves(cur->num, i, list_a);
	while (i < 4 && in_range(cur->num, d)) //also figure out what to do when len < 4
	{
		moves = calc_moves(cur->num, i, list_a);
		if (moves < m->min_move)
		{
			m->min_move = moves;
			m->n = cur->num;
			m->i = i;
		}
		i++;
		cur = cur->next;
	}
	move_num(list_a, list_b, m);	
}


int	calc_moves(int num, int index_b, t_nlist **list_a, t_mlist *m)
{
	// int	index_a;
	// int	mid_a;
	// int	mid_b;
	// int	len_a;
	// int	len_b;
	// int	moves;
	t_calc c;

	// if (num < min || num > max)
	// {
	// 	//if normal triangle
	// 		//if min, moves_a = 0;
	// 		//if max, moves_a = 2;
	// 	//if not normal triangle
	// 		//moves_a is related to minimum number index
	// }
	// 	// index_a = (find_min_index(min, list_a)); 
	c.index_a = find_new_index(num, list_a, m); 
	c.len_a = len_list(list_a);
	c.len_b = len_list(list_b);
	c.mid_a = (len_a / 2) - 1;
	c.mid_b = (len_b / 2) - 1;
	if (c.index_a > c.mid_a && index_b > c.mid_b)
	{
		if (c.len_a - c.index_a >= c.len_b - index_b)
			c.moves = c.len_a - c.index_a;
		else
			c.len_b - index_b
	}
	else if (c.index_a <= c.mid_a && c.index_b <= mid_b)
	{
		if (c.index_a >= c.index_b)
			c.moves = c.index_a;
		else
			c.moves = c.index_b;
	}
	else if(index_a > mid_a && index_b <= mid_b)
		c.moves = (len_a - index_a) + index_b;
	else if (index_a <= mid_a && index_b > mid_b)
		c.moves = index_a + (len_b - index_b);
	return (c.moves);
}

void	find_best_move(t_nlist **list_a, t_nlist **list_b, t_dlist *d, t_mlist *m)
{
	//note: figure out what happens when len of list_b < 4
	int		index_a;
	int		index_b;
	int		moves;
	int		len_b;
	t_nlist *cur;

	//check top
	cur = *list_b;
	index_a = find_new_index(cur->num, list_a, m);
	index_b = 0;
	m->min_move = calc_moves(index_a, index_b, list_a, list_b);
	m->index_a = index_a;
	m->index_b = index_b;
	while (index_b < 4 && in_range(cur->num, d, 's'))
	{	
		moves = calc_moves(index_a, index_b, list_a, list_b);
		if (moves < m->min_move)
		{
			m->min_move = moves;
			m->index_a = index_a;
			m->index_b = index_b;
		}
		cur = cur->next;
		index_a = find_new_index(cur->num, list_a, m);
		index_b ++;
	}

	//check bottom
	cur = (*list_b)->prev;
	len_b = len_list(list_b) - 1;
	index_a = find_new_index(cur->num, list_a, m);
	index_b = len_b;
	while (index_b >= len_b - 4 && in_range (cur->num, d, 's'))
	{
		moves = calc_moves(cur->num, i, list_a);
		if (moves < m->min_move)
		{
			m->min_move = moves;
			m->index_a = find_index(cur-num, list_a);
			m->index_b = i;
			m->num = cur->num;
		}
		cur = cur->prev;
		index_a = find_new_index(cur->num, list_a, m);
		index_b --;
	}
}

void	push_move(t_nlist **list_a, t_nlist **list_b, t_mlist *m)
{
	int	mid_a;
	int	mid_b;

	mid_a = ft_round((len_list(list_a) / (float)2) - 1);
	mid_b = ft_round((len_list(list_b) / (float)2) - 1);
	if (m->index_a <= mid_a && m->index_b <= mid_b)
	{
		printf("index a and index b <= mid\n");
		while ((*list_a)->num <= m->n && (*list_b)->num != m->n)
			rotate(list_a, list_b, 'r');
		while((*list_a)->num <= m->n)
			rotate(list_a, list_b, 'a');
		while((*list_b)->num != m->n)
			rotate(list_a, list_b, 'b');
	}
	else if (m->index_a > mid_a && m->index_b > mid_b)
	{
		printf("index a and index b > mid\n");
		while ((*list_a)->num > m->n && (*list_b)->num != m->n)
			rev_rotate(list_a, list_b, 'r');
		while((*list_a)->num > m->n)
			rev_rotate(list_a, list_b, 'a');
		while((*list_b)->num != m->n)
			rev_rotate(list_a, list_b, 'b');
	}
	else if (m->index_a <= mid_a && m->index_b > mid_b)
	{
		printf("index a <= mid and index b > mid\n");
		while((*list_a)->num <= m->n)
			rotate(list_a, list_b, 'a');
		while((*list_b)->num != m->n)
			rev_rotate(list_a, list_b, 'b');
	}
	else if (m->index_a > mid_a && m->index_b <= mid_b)
	{
		printf("index a > mid and index b <= mid\n");
		while((*list_a)->num > m->n)
			rev_rotate(list_a, list_b, 'a');
		while((*list_b)->num != m->n)
			rotate(list_a, list_b, 'b');
	}
	push(list_a, list_b, 'a');
}