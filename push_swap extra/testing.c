#include "push_swap.h"

void	print_list(t_nlist **list, char c)
{
	int	i;
	t_nlist *cur;

	if (list && *list)
	{
		cur = *list;
		i = (*list)->num;
		printf("%c: %i ", c, cur->num);
		cur = cur->next;
		while (cur->num != i)
		{
			printf("%i ", cur->num);
			cur = cur->next;
		}
		printf("\n");
	}
	else
		printf("*%c* list is empty\n", c);
}

void	print_dlist(t_data *list)
{
	printf("top->num: %i\n", list->top->num);
	printf("bottom->num: %i\n", list->bottom->num);
	printf("t_index: %i\n", list->t_index);
	printf("b_index: %i\n", list->b_index);
	printf("buckets: %i\n", list->buckets);
	printf("len: %i\n", list->len);
	printf("min: %i\n", list->min);
	printf("max: %i\n", list->max);
	printf("i: %i\n", list->i);
	printf("j: %i\n", list->j);
	printf("PIVOTS\n");
	for (int i = 0; i <= list->buckets; i++)
		printf("%i ", list->pivots[i]);
	printf("\nSUBPIVOTS\n");
	for (int j = 0; j < list->buckets; j++)
		printf("%i ", list->subpivots[j]);
	printf("\nALLPIVOTS\n");
	for (int k = 0; k <= 2* list->buckets; k++)
		printf("%i ", list->allpivots[k]);
	printf("\n");
}

void	print_mlist(t_mlist *list)
{
	printf("min_move: %i\n", list->min_move);
	printf("num: %i\n", list->n);
	printf("index_a: %i\n", list->index_a);
	printf("index_b: %i\n", list->index_b);
	printf("cur_min: %i\n", list->cur_min);
	printf("cur_max: %i\n", list->cur_max);
}